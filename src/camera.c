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

void			default_view(t_fdf *f)
{
	int			y;
	int			x;
	
	y = 0;
	while (y < f->h)
	{
		x = 0;
		while (x < f->w)
		{
			f->map[y][x].x = (x - f->w / 2) * f->zoom;
			f->map[y][x].y = (y - f->h / 2) * f->zoom;
			f->map[y][x].x += f->x0;
			f->map[y][x].y += f->y0;
			x++;
		}
		y++;
	}
}

void			iso(t_fdf *f, int *x, int *y, int z)
{
	int		old_x;
	int 	old_y;

	old_x = *x;
	old_y = *y;
	*x = (old_x - old_y) * cos(0.523599);
	*y = (old_x + old_y -z) * sin(0.523599);
	(void)f;	///
//	*x += f->xm;
//	*y += f->ym;
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
			f->map[y][x].x = (x - f->w / 2) * f->zoom;
			f->map[y][x].y = (y - f->h / 2) * f->zoom;
			iso(f, &f->map[y][x].x, &f->map[y][x].y, (f->map[y][x].z * f->zoom));
			f->map[y][x].x += f->x0;
			f->map[y][x].y += f->y0;
			x++;
		}
		y++;
	}
}

void			view(t_fdf *f)
{
//		printf("zoom: %f\n", f->zoom);		///
	if (f->view == 0)
		default_view(f);
	else if (f->view == 1)
		to_isometric(f);
//	rotate(f);
}
