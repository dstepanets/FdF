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

t_fdf			*init_fdf(void)
{
	t_fdf	*f;

	if(!(f = (t_fdf *)malloc(sizeof(t_fdf))))
		return (NULL);
	f->h = 0;
	f->w = 0;
	f->map = NULL;
	f->view = 0;
	f->zoom = 0.7;
	f->xs = 1;
	f->ys = 1;
	f->mlx = NULL;
	f->win = NULL;
	return (f);
}

void			reset_fdf(t_fdf *f)
{
	mlx_clear_window(f->mlx, f->win);
	f->xs = WIN_W / f->w * f->zoom;
	f->ys = WIN_H / f->h * f->zoom;
}

void			fdf(t_fdf *f)
{

	view(f);
	draw_grid(f);
}

void			run_mlx(t_fdf *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN_W, WIN_H, "FdF");
		
		fdf(f);

	mlx_hook(f->win, 2, 0, key_press, f);
	mlx_hook(f->win, 17, 0, exit_fdf, f);
	mlx_loop(f->mlx);
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
	if (!map_z(f, file))
		fdf_error("ERROR: invalid map.");
	ft_memdel((void **)&file);
	default_view(f);
//			print_map(f);		///
	to_isometric(f);
	run_mlx(f);


		printf("\n#################################################\n");		///
		system("leaks -q fdf");		///
	return (0);
}
