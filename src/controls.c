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
	if (key == 18)
	{
		f->view = 0;
		reset_fdf(f);
		fdf(f);
	}
	if (key == 19)
	{
		f->view = 1;
		reset_fdf(f);
		fdf(f);
	}
	if (key == 27 || key == 78)
	{
		(f->zoom > 0.1) ? f->zoom -= 0.01 : 0;
		reset_fdf(f);
		fdf(f);
	}
	if (key == 24 || key == 69)
	{
		f->zoom += 0.01;
		reset_fdf(f);
		fdf(f);
	}
	return (0);
}
