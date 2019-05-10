/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:03:46 by dstepane          #+#    #+#             */
/*   Updated: 2019/05/01 18:03:47 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

//void			put_pixel(t_fdf *f, int x, int y, int z)

void			put_pixel(t_fdf *f, int x, int y, int color)
{
	int		i;

	if (x > 0 && x < WIN_W && y > 0 && y < WIN_H)
	{
		i = y * WIN_W + x;
//		f->imarr[i] = get_color(f);
		f->imarr[i] = color;
	}
}

void			line_low(t_fdf *f, struct s_dots s, struct s_dots e)
{
	struct s_line		l;

	l.dx = e.x - s.x;
	l.dy = e.y - s.y;
	l.yi = 1;
	if (l.dy < 0)
	{
		l.yi = -1;
		l.dy = -l.dy;
	}
	l.d = 2 * l.dy - l.dx;
	l.y = s.y;
	l.x = s.x;
	while (l.x <= e.x)
	{
		put_pixel(f, l.x, l.y, GREEN);
		if (l.d > 0)
		{
			l.y = l.y + l.yi;
			l.d = l.d - 2 * l.dx;
		}
		l.d = l.d + 2 * l.dy;
		l.x++;
	}
}

void			line_high(t_fdf *f, struct s_dots s, struct s_dots e)
{
	struct s_line		l;

	l.dx = e.x - s.x;
	l.dy = e.y - s.y;
	l.xi = 1;
	if (l.dx < 0)
	{
		l.xi = -1;
		l.dx = -l.dx;
	}
	l.d = 2 * l.dx - l.dy;
	l.x = s.x;
	l.y = s.y;
	while (l.y <= e.y)
	{
		put_pixel(f, l.x, l.y, GREEN);
		if (l.d > 0)
		{
			l.x += l.xi;
			l.d = l.d - 2 * l.dy;
		}
		l.d = l.d + 2 * l.dx;
		l.y++;
	}
}

void			draw_line(t_fdf *f, struct s_dots s, struct s_dots e)
{
	if (abs(e.x - s.x) > abs(e.y - s.y))
		(s.x > e.x) ? line_low(f, e, s) : line_low(f, s, e);
	else
		(s.y > e.y) ? line_high(f, e, s) : line_high(f, s, e);
}

void			draw_grid(t_fdf *f)
{
	int		y;
	int		x;

	y = 0;
	while (y < f->h)
	{
		x = 0;
		while (x < f->w)
		{
			if (y + 1 < f->h)
				draw_line(f, f->map[y][x], f->map[y + 1][x]);
			if (x + 1 < f->w)
				draw_line(f, f->map[y][x], f->map[y][x + 1]);
			x++;
		}
		y++;
	}
}
