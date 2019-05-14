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

int			rotation_mode(t_fdf *f)
{
	if (f->view == 5)
	{
		f->angle_x = -45;
		f->angle_z = 0;
		f->angle_y++;
		usleep(20000);
		fdf(f);
	}
	return (0);
}

void			reset_view(t_fdf *f)
{
	f->x0 = WIN_W / 2;
	f->y0 = WIN_H / 2;
	if (f->w > f->h)
		f->zoom = WIN_W / 2 / f->w;
	else
		f->zoom = WIN_H / 2 / f->h;
	if (f->zoom < 1)
		f->zoom = 1;
	f->z_scale = 1.0;
	f->view = 0;
	f->colors[0] = NAVY;
	f->colors[1] = RED;
}

void			view(t_fdf *f)
{
	dots_color(f);
	if (f->view == 0)
	{
		f->angle_x = -30;
		f->angle_y = -30;
		f->angle_z = 30;
	}
	else if (f->view == 1)
	{
		f->angle_x = 0;
		f->angle_y = 0;
		f->angle_z = 0;
	}
	rotate(f);
}
