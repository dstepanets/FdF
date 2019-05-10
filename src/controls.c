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
		reset_fdf(f);
//		view(f);
		fdf(f);
	}
	switch_view(key, f);
	scroll(key, f);
	zoom(key, f);
	if (key == 13 || key == 1 || key == 2 || key == 0 || key == 14 || key == 12)
		rotate_controls(key, f);
	return (0);
}

int				switch_view(int key, t_fdf *f)
{
	if (key == 18)
	{
		f->view = 0;
		fdf(f);
	}
	else if (key == 19)
	{
		f->view = 1;
		fdf(f);
	}
	else if (key == 20)
	{
		f->view = 2;
		fdf(f);
	}
	return (0);
}

int				scroll(int key, t_fdf *f)
{
	if (key == 126)
	{
		f->y0 -= 8;
		fdf(f);
	}
	else if (key == 125)
	{
		f->y0 += 8;
		fdf(f);
	}
	else if (key == 123)
	{
		f->x0 -= 8;
		fdf(f);
	}
	else if (key == 124)
	{
		f->x0 += 8;
		fdf(f);
	}
	return (0);
}

int				zoom(int key, t_fdf *f)
{
	if (key == 27 || key == 78)
	{
		(f->zoom > 1) ? f->zoom-- : 0;
		fdf(f);
	}
	else if (key == 24 || key == 69)
	{
		f->zoom++;
		fdf(f);
	}
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
	f->view = 2;
	fdf(f);
	return (0);
}