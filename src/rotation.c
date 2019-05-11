/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:16:48 by dstepane          #+#    #+#             */
/*   Updated: 2019/05/02 19:16:50 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			rotate_x(t_fdf *f, int *y, double *z)
{
	double		old_y;
	double		new_y;

	old_y = *y;
	new_y = old_y * cos(PI / 180 * f->angle_x) + *z * sin(PI / 180 * f->angle_x);
	*z = -old_y * sin(PI / 180 * f->angle_x) + *z * cos(PI / 180 * f->angle_x);
	*y = new_y;
}

void			rotate_y(t_fdf *f, int *x, double *z)
{
	double		old_x;
	double		new_x;

	old_x = *x;
	new_x = old_x * cos(PI / 180 * f->angle_y) + *z * sin(PI / 180 * f->angle_y);
	*z = -old_x * sin(PI / 180 * f->angle_y) + *z * cos(PI / 180 * f->angle_y);
	*x = new_x;
}

void			rotate_z(t_fdf *f, int *x, int *y)
{
	double		old_x;
	double		old_y;
	double		new_x;
	double		new_y;

	old_x = *x;
	old_y = *y;
	new_x = old_x * cos(PI / 180 * f->angle_z) - old_y * sin(PI / 180 * f->angle_z);
	new_y = old_x * sin(PI / 180 * f->angle_z) + old_y * cos(PI / 180 * f->angle_z);
	*x = new_x;
	*y = new_y;
}

void			rotate(t_fdf *f)
{
	int		y;
	int		x;
	double	tmp_z;

	y = 0;
	while (y < f->h)
	{
		x = 0;
		while (x < f->w)
		{
			f->map[y][x].x = (x - f->w / 2) * f->zoom;
			f->map[y][x].y = (y - f->h / 2) * f->zoom;
			tmp_z = f->map[y][x].z * f->zoom * f->z_scale;
			rotate_x(f, &f->map[y][x].y, &tmp_z);
			rotate_y(f, &f->map[y][x].x, &tmp_z);
			rotate_z(f, &f->map[y][x].x, &f->map[y][x].y);
			f->map[y][x].x += f->x0;
			f->map[y][x].y += f->y0;
			x++;
		}
		y++;
	}
}

