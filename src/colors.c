/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 12:54:05 by dstepane          #+#    #+#             */
/*   Updated: 2019/05/12 12:54:07 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int				get_pixel_color(struct s_line ln)
{
	int			rgb[3];
	double 		rat;

	rat = (ln.dx > ln.dy) ? ratio(ln.x, ln.s, ln.e) : ratio(ln.y, ln.s, ln.e);
	rgb[0] = light_my_fire((ln.s_color >> 16) & 0xFF, (ln.e_color >> 16) & 0xFF, rat);
	rgb[1] = light_my_fire((ln.s_color >> 8) & 0xFF, (ln.e_color >> 8) & 0xFF, rat);
	rgb[2] = light_my_fire(ln.s_color & 0xFF, ln.e_color & 0xFF, rat);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

int				light_my_fire(int low, int high, double rat)
{
	int		light;

	light = (int)((1 - rat) * low + rat * high);
	return (light);
}

double			ratio(int cur, int low, int high)
{
	double		rat;
	double		range;
	double		position;

	range = high - low;
	position = cur - low;
	rat = (range == 0) ? 1.0 : (position / range);
	if (rat < 0.0)
		rat = 0.0;
	return (rat);
}

int				get_dots_color(t_fdf *f, int z)
{
	int			rgb[3];
	double 		rat;

	rat = ratio(z, f->min_z, f->max_z);
	rgb[0] = light_my_fire((f->colors[0] >> 16) & 0xFF, (f->colors[1] >> 16) & 0xFF, rat);
	rgb[1] = light_my_fire((f->colors[0] >> 8) & 0xFF, (f->colors[1] >> 8) & 0xFF, rat);
	rgb[2] = light_my_fire(f->colors[0] & 0xFF, f->colors[1] & 0xFF, rat);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void			dots_color(t_fdf *f)
{
	int			y;
	int			x;

	y = 0;
	while (y < f->h)
	{
		x = 0;
		while (x < f->w)
		{
			f->map[y][x].color = get_dots_color(f, f->map[y][x].z);
			x++;
		}
		y++;
	}
}
