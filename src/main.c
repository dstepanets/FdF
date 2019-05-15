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

	if (!(f = (t_fdf *)malloc(sizeof(t_fdf))))
		return (NULL);
	f->h = 0;
	f->w = 0;
	f->map = NULL;
	f->img = NULL;
	f->imarr = NULL;
	f->max_z = 0;
	f->min_z = 0;
	f->controls = on;
	f->mlx = NULL;
	f->win = NULL;
	return (f);
}

void			fdf(t_fdf *f)
{
	ft_bzero(f->imarr, WIN_W * WIN_H * sizeof(int));
	mlx_clear_window(f->mlx, f->win);
	view(f);
	draw_grid(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	if (f->controls == on)
		display_controls(f);
}

void			run_mlx(t_fdf *f)
{
	int		t[3];

	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN_W, WIN_H, "FdF");
	f->img = mlx_new_image(f->mlx, WIN_W, WIN_H);
	f->imarr = (int *)mlx_get_data_addr(f->img, &t[0], &t[1], &t[2]);
	reset_view(f);
	fdf(f);
	mlx_hook(f->win, 2, 0, key_press, f);
	mlx_hook(f->win, 17, 0, exit_fdf, f);
	mlx_loop_hook(f->mlx, rotation_mode, f);
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
	f->h = get_map_height(file);
	f->w = get_map_width(file);
	if (!f->h || !f->w)
		fdf_error("ERROR: invalid map.");
	if (!create_map(f))
		fdf_error("ERROR on map creation.");
	if (!validate(f, file))
		fdf_error("ERROR: invalid map.");
	ft_memdel((void **)&file);
	run_mlx(f);
	return (0);
}
