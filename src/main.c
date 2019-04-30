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
	f->map = NULL;
	if(!(f->ln = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	return (f);
}

int				key_press(int key, void *f)
{
	if (key == 53)
		exit_fdf(f);
	
	return (0);
}

void			init_mlx(t_fdf *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN_W, WIN_H, "FdF");
	mlx_hook(f->win, 2, 0, key_press, f);
	mlx_hook(f->win, 17, 0, exit_fdf, f);
		draw_line(f);
	mlx_loop(f->mlx);
}


void			draw_line(t_fdf *f)
{
	f->ln->x1 = 50;
	f->ln->y1 = 50;
	f->ln->x2 = WIN_H - 50;
	f->ln->y2 = WIN_W - 50;
	while (f->ln->x1 < f->ln->x2 && f->ln->y1 < f->ln->y2)
	{
		mlx_pixel_put(f->mlx, f->win, f->ln->x1++, f->ln->y1++, BLUE);
	}
	f->ln->x1 = 100;
	f->ln->y1 = 50;
	f->ln->x2 = WIN_H - 50;
	f->ln->y2 = WIN_W - 50;
	while (f->ln->x1 < f->ln->x2 && f->ln->y1 < f->ln->y2)
	{
		mlx_pixel_put(f->mlx, f->win, f->ln->x1++, f->ln->y1++, NAVY);
	}
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
	ft_memdel((void **)&file);

	init_mlx(f);




		printf("\n#################################################\n");		///
		system("leaks -q fdf");		///
	return (0);
}
