/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:18:30 by dstepane          #+#    #+#             */
/*   Updated: 2019/05/01 18:18:31 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int				key_press(int key, t_fdf *f)
{
	if (key == 53)
		exit_fdf(f);
	else if (key == 49)
	{
		reset_view(f);
		fdf(f);
	}
	else if (key == 18 || key == 19)
		switch_view(key, f);
	else if (key == 126 || key == 125 || key == 123 || key == 124)
		scroll(key, f);
	else if (key == 27 || key == 78 || key == 24 || key == 69)
		zoom(key, f);
	else if (key == 13 || key == 1 || key == 2 || key == 0 || key == 14 || key == 12)
		rotate_controls(key, f);
	else if (key == 116 || key == 121)
		z_scale(key, f);
	return (0);
}

int				switch_view(int key, t_fdf *f)
{
	if (key == 18)
		f->view = 0;
	else if (key == 19)
		f->view = 1;
	fdf(f);
	return (0);
}

int				scroll(int key, t_fdf *f)
{
	if (key == 126)
		f->y0 -= 8;
	else if (key == 125)
		f->y0 += 8;
	else if (key == 123)
		f->x0 -= 8;
	else if (key == 124)
		f->x0 += 8;
	fdf(f);
	return (0);
}

int				zoom(int key, t_fdf *f)
{
	if (key == 27 || key == 78)
		(f->zoom > 1) ? f->zoom-- : 0;
	else if (key == 24 || key == 69)
		f->zoom++;
	fdf(f);
	return (0);
}

int				rotate_controls(int key, t_fdf *f)
{
	if (key == 13)
		f->angle_x -= 2;
	else if (key == 1)
		f->angle_x += 2;
	else if (key == 2)
		f->angle_y += 2;
	else if (key == 0)
		f->angle_y -= 2;
	else if (key == 14)
		f->angle_z += 2;
	else if (key == 12)
		f->angle_z -= 2;
	f->view = 3;
	fdf(f);
	return (0);
}

int				z_scale(int key, t_fdf *f)
{
	if (key == 121 && f->z_scale > 0.1)
		f->z_scale -= 0.1;
	else if (key == 116 && f->z_scale < 10.0)
		f->z_scale += 0.1;
	fdf(f);
	return (0);
}