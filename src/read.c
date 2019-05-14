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

int				is_hex(char *file, int *i)
{
	int		j;
	int		l;

	j = *i + 2;
	l = 0;
	while (file[j] && ((file[j] >= '0' && file[j] <= '9') ||
			(file[j] >= 'A' && file[j] <= 'F') ||
			(file[j] >= 'a' && file[j] <= 'f')))
	{
		j++;
		l++;
	}
//		printf("*i: %d, j: %d, l: %d\n", *i, j, l);		///
	if (l == 6 || l == 4 || l == 2)
	{
		*i += l + 2;
		return(1);
	}
	return (0);
}

void		int_limits(char *file, int i)
{
	int			j;
	char		*n;
	static char		*imax = "2147483647";
	static char		*imin = "-2147483648";

	j = i;
	while (ft_isdigit(file[i]) || file[i] == '-')
		i++;
//		printf("i: %d, j: %d\n", i, j);		//
	n = ft_strsub(file, j, i - j);
//		printf("n:: %s||\n", n);		//
	if ((n[0] != '-' && ft_strlen(n) > 10) ||
	(n[0] == '-' && ft_strlen(n) > 11))
		fdf_error("ERROR: altitude must be an int.");
	if ((n[0] != '-' && ft_strlen(n) == 10) ||
		(n[0] == '-' && ft_strlen(n) == 11))
	{
		if ((n[0] != '-') && (ft_strcmp(n, imax) > 0))
			fdf_error("ERROR: altitude must be an int.");
		if ((n[0] == '-') && (ft_strcmp(n, imin) > 0))
			fdf_error("ERROR: altitude must be an int.");
	}
	ft_strdel(&n);
}

int			map_z(t_fdf *f, int *ixy, char *file)
{
	if (ixy[1] >= f->w)
		return (0);
	int_limits(file, ixy[0]);
	f->map[ixy[2]][ixy[1]].z = ft_atoi(&file[ixy[0]]);
	if (f->map[ixy[2]][ixy[1]].z > f->max_z)
		f->max_z = f->map[ixy[2]][ixy[1]].z;
	else if (f->map[ixy[2]][ixy[1]].z < f->min_z)
		f->min_z = f->map[ixy[2]][ixy[1]].z;
	ixy[1]++;
	while (file[ixy[0]] && (file[ixy[0]] == '-' || ft_isdigit(file[ixy[0]])))
		ixy[0]++;
	return (1);
}

int				validate(t_fdf *f, char *file)
{
	static int		ixy[3] = {0, 0, 0};

	while (file[ixy[0]])
	{
		if (file[ixy[0]] == '0' && file[ixy[0] + 1] == 'x')
			is_hex(file, &ixy[0]);
		if (file[ixy[0]] == '-' || ft_isdigit(file[ixy[0]]))
		{
			if (!map_z(f, ixy, file))
				return (0);
		}
		if (!file[ixy[0]] || file[ixy[0]] == '\n')
		{
			if (ixy[1] != f->w)
				return (0);
			ixy[2]++;
			ixy[1] = 0;
		}
		(file[ixy[0]]) ? ixy[0]++ : 0;
	}
	if (ixy[2] != f->h)
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
		if (file[i] == '0' && file[i + 1] == 'x')
			is_hex(file, &i);
		if (ft_isdigit(file[i]))
		{
			w++;
			while (ft_isdigit(file[i]))
				i++;
		}
		if (!file[i] || file[i] == '\n')
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
