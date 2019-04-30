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
		draw_line(f, f->map[0][0], f->map[5][1]);
	mlx_loop(f->mlx);
}


void			draw_line(t_fdf *f, struct s_dots s, struct s_dots e)
{
	struct s_line		l;

	l.x = s.x;
	l.y = s.y;
	l.dx = abs(s.x - e.x);
	l.dy = abs(s.y - e.y);
	l.p = 2 * l.dy - l.dx;
	if (s.x > e.x)
	{
		l.x = e.x;
		l.y = e.y;
		l.t = s.x;
	}
	else
	{
		l.x = s.x;
		l.y = s.y;
		l.t = e.x;
	}
	mlx_pixel_put(f->mlx, f->win, l.x++, l.y, BLUE);
	while (l.x <= l.t)
	{
		l.x++;
		if (l.p < 0)
			l.p = l.p + 2 * l.dy;
		else
		{
			l.y++;
			l.p = l.p + 2 * (l.dy - l.dx);
		}
		mlx_pixel_put(f->mlx, f->win, l.x, l.y, BLUE);
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
	if (!map_z(f, file))
		fdf_error("ERROR: invalid map.");
			print_map(f);		///
	ft_memdel((void **)&file);
	map_xy(f);

	init_mlx(f);


		printf("\n#################################################\n");		///
		system("leaks -q fdf");		///
	return (0);
}
