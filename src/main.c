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
	f->x0 = 0;
	f->y0 = 0;
	f->grid_step = 1;
	f->grid_step = 1;
	f->view = 0;
	f->zoom = 0.7;
	f->angle_x = 0.0;
	f->angle_y = 0.0;
	f->angle_z = 0.0;
	f->mlx = NULL;
	f->win = NULL;
	return (f);
}

void			reset_fdf(t_fdf *f)
{
	f->zoom = 0.7;
	f->angle_x = 0.0;
	f->angle_y = 0.0;
	f->angle_z = 0.0;
	if (f->w > f->h)
		f->grid_step = WIN_W / (f->w - 1) * f->zoom;
	else
		f->grid_step = WIN_H / (f->h - 1) * f->zoom;
	f->x0 = (WIN_W - ((f->w - 1) * f->grid_step)) / 2;
	f->y0 = (WIN_H - ((f->h - 1) * f->grid_step)) / 2;
}

void			fdf(t_fdf *f)
{
	mlx_clear_window(f->mlx, f->win);
	if (f->w > f->h)
		f->grid_step = WIN_W / (f->w - 1) * f->zoom;
	else
		f->grid_step = WIN_H / (f->h - 1) * f->zoom;
	view(f);
	draw_grid(f);
}

void			run_mlx(t_fdf *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN_W, WIN_H, "FdF");
		
		reset_fdf(f);
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
//			print_map(f);		///

	run_mlx(f);


		printf("\n#################################################\n");		///
		system("leaks -q fdf");		///
	return (0);
}
