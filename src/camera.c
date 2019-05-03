/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:35:33 by dstepane          #+#    #+#             */
/*   Updated: 2019/05/01 18:35:34 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			parallel(t_fdf *f)
{
	int			y;
	int			x;

	f->map[0][0].x = f->x0;
	f->map[0][0].y = f->y0;
	y = 0;
	while (y < f->h)
	{
		x = 0;
		while (x < f->w)
		{
			if (x == 0 && y == 0)
			{
				x++;
				continue ;
			}
			f->map[y][x].x = f->map[0][0].x + (x * f->grid_step);
			f->map[y][x].y = f->map[0][0].y + (y * f->grid_step);
			x++;
		}
		y++;
	}
}

void			iso(int *x, int *y, int z)
{
	int		old_x;
	int 	old_y;

	old_x = *x;
	old_y = *y;
	*x = (old_x - old_y) * cos(0.523599);
	*y = (old_x + old_y -z) * sin(0.523599);
}

void			to_isometric(t_fdf *f)
{
	int		y;
	int		x;

	y = 0;
	while (y < f->h)
	{
		x = 0;
		while (x < f->w)
		{
			iso(&f->map[y][x].x, &f->map[y][x].y, f->map[y][x].z);
			x++;
		}
		y++;
	}
}

void			view(t_fdf *f)
{

	if (f->view == 1)
		to_isometric(f);
	else
		parallel(f);
	rotate(f);
}
