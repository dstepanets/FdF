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

void			rotate_x(t_fdf *f, int *y, int *z)
{
	int		old_y;
	int		old_z;

	old_y = *y;
	old_z = *z;
	*y = old_y * cos(f->angle_x) + *z * sin(f->angle_x);
	*z = -old_y * sin(f->angle_x) + *z * cos(f->angle_x);
}

void			rotate_y(t_fdf *f, int *x, int *z)
{
	int		old_x;
	int		old_z;

	old_x = *x;
	old_z = *z;
	*x = old_x * cos(f->angle_y) + *z * sin(f->angle_y);
	*z = -old_x * sin(f->angle_y) + *z * cos(f->angle_y);
}

void			rotate_z(t_fdf *f, int *x, int *y)
{
	int		old_x;
	int		old_y;

	old_x = *x;
	old_y = *y;
	*x = old_x * cos(f->angle_z) - old_y * sin(f->angle_z);
	*y = old_x * sin(f->angle_z) + old_y * cos(f->angle_z);
}

void			rotate(t_fdf *f)
{
	int		y;
	int		x;

	y = 0;
	while (y < f->h)
	{
		x = 0;
		while (x < f->w)
		{
			rotate_x(f, &f->map[y][x].y, &f->map[y][x].z);
			rotate_y(f, &f->map[y][x].x, &f->map[y][x].z);
			rotate_z(f, &f->map[y][x].x, &f->map[y][x].y);
			x++;
		}
		y++;
	}
}

