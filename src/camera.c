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

void			reset_view(t_fdf *f)
{
	if (f->w > f->h)
		f->zoom = WIN_W / 2 / (f->w - 1);
	else
		f->zoom = WIN_H / 2 / (f->h - 1);
	if (f->zoom < 1)
		f->zoom = 1;
	f->z_scale = 1.0;
	f->view = 0;
}

void			view(t_fdf *f)
{
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
/*

	if (f->view == 0)
		default_view(f);
	else if (f->view == 1)
		to_isometric(f);
	else
		rotate(f);
*/