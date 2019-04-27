/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:16:58 by dstepane          #+#    #+#             */
/*   Updated: 2019/04/25 19:16:59 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			fdf_error(char *msg)
{
	ft_printf("{red}{b}%s{0}\n", msg);
		printf("\n#################################################\n");		///
		system("leaks -q fdf");		///
	exit(0);
}

t_fdf			*init_fdf(void)
{
	t_fdf	*f;

	if(!(f = (t_fdf *)malloc(sizeof(t_fdf))))
		return (NULL);
	f->map = NULL;
//	f->mlx = mlx_init();
//	f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
//	mlx_loop(f->mlx);
	return (f);
}

int				main(int ac, char const *av[])
{
	t_fdf	*f;
	char	*file;

	if (ac != 2)
	{
		ft_printf("{yellow}{b}USAGE: ./fdf [file.fdf]{0}\n");
		exit(0);
	}
	f = init_fdf();
	file = read_file(av[1]);
		printf("file:\n%s\n", file);	///
	f->h = get_map_height(file);
		printf("map_h: %d\n", f->h);	///
	f->w = get_map_width(file);
		printf("map_w: %d\n", f->w);	///
	if (!f->h || !f->w)
		fdf_error("ERROR: invalid map.");
	if (!create_map(f))
		fdf_error("ERROR on map creation.");
	if (!populate_map(f, file))
		fdf_error("ERROR: invalid map.");
			print_map(f);		///

	del_map(f);
	ft_memdel((void **)&file);
	free(f);
		printf("\n#################################################\n");		///
		system("leaks -q fdf");		///
	return (0);
}
