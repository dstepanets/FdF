/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:19:03 by dstepane          #+#    #+#             */
/*   Updated: 2019/04/26 19:19:05 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int				map_z(t_fdf *f, char *file)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	x = 0;
	while (file[i])
	{
		if (file[i] == '-' || ft_isdigit(file[i]))
		{
			f->map[y][x].z = ft_atoi(&file[i]);
			x++;
			if (x > f->w)
				return (0);
			while (file[i] && (file[i] == '-' || ft_isdigit(file[i])))
				i++;
		}
		if (!file[i] || file[i] == '\n')
		{
//				printf("y: %d, x: %d\n", y, x);	///
			if (x != f->w)
				return (0);
			y++;
			x = 0;
		}
		if (file[i])
			i++;
	}
	if (y != f->h)
		return (0);
	return (1);
}

int				create_map(t_fdf *f)
{
	int		y;
	
	if (!(f->map = (t_dots **)malloc(sizeof(t_dots *) * f->h + 1)))
		return (0);
	y = 0;
	while (y < f->h)
	{
		if (!(f->map[y] = (t_dots *)malloc(sizeof(t_dots) * f->w)))
			return (0);
		y++;
	}
	f->map[y] = NULL;
	return (1);
}

int				get_map_width(char		*file)
{
	int		w;
	int		i;

	w = 0;
	i = 0;
	while (file[i])
	{
		if (ft_isdigit(file[i]))
		{
			w++;
			while (ft_isdigit(file[i]))
				i++;
		}
		if (file[i] == '\n')
			break ;
		i++;
	}
	return (w);
}

int				get_map_height(char		*file)
{
	int			h;
	intmax_t	i;

	h = 0;
	i = 0;
	while (file[i])
	{
		if (file[i] == '\n')
			h++;
		i++;
	}
	if (i != 0 && file[i] == '\0' && file[i - 1] != '\n')
		h++;
	return (h);
}

char			*read_file(const char *av)
{
	int		fd;
	char	*file;
	char	buf[BUFF_SIZE + 1];
	int		r;
	char	*tmp;

	if ((fd = open(av, O_RDONLY)) < 0)
		fdf_error("ERROR: Can't open the file.");
	file = ft_strnew(1);
	while((r = read(fd, buf, BUFF_SIZE)))
	{
		if (r < 0)
			fdf_error("ERROR on reading the file.");
		buf[r] = '\0';
		tmp = ft_strjoin(file, buf);
		ft_memdel((void **)&file);
		file = tmp;
	}
	close(fd);
	return (file);
}
