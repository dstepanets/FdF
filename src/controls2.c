/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:08:20 by dstepane          #+#    #+#             */
/*   Updated: 2019/05/13 18:08:22 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			display_controls(t_fdf *f)
{
	mlx_string_put(f->mlx, f->win, 10, 10, BEIGE, "CONTROLS     [TAB]");
	mlx_string_put(f->mlx, f->win, 10, 30, BEIGE, "iso/parallel [Enter]");
	mlx_string_put(f->mlx, f->win, 10, 50, BEIGE, "scroll       [arrowkeys]");
	mlx_string_put(f->mlx, f->win, 10, 70, BEIGE, "rotate on X  [W]/[A]");
	mlx_string_put(f->mlx, f->win, 10, 90, BEIGE, "rotate on Y  [A]/[D]");
	mlx_string_put(f->mlx, f->win, 10, 110, BEIGE, "rotate on Z  [Q]/[E]");
	mlx_string_put(f->mlx, f->win, 10, 130, BEIGE, "auto-rotate  [backspace]");
	mlx_string_put(f->mlx, f->win, 10, 150, BEIGE, "zoom         [+]/[-]");
	mlx_string_put(f->mlx, f->win, 10, 170,
										BEIGE, "scale Z      [PgUp]/[PgDwn]");
	mlx_string_put(f->mlx, f->win, 10, 190, BEIGE, "color modes  [1] - [5]");
	mlx_string_put(f->mlx, f->win, 10, 210, BEIGE, "reset view   [space]");
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

static int		color_mode2(int key, t_fdf *f)
{
	if (key == 21)
	{
		f->colors[0] = SKY;
		f->colors[1] = GINGER;
	}
	else if (key == 23)
	{
		f->colors[0] = SAPPHIRE;
		f->colors[1] = AQUA;
	}
	return (0);
}

int				color_mode(int key, t_fdf *f)
{
	if (key == 18)
	{
		f->colors[0] = NAVY;
		f->colors[1] = RED;
	}
	else if (key == 19)
	{
		f->colors[0] = DARK_GRAY;
		f->colors[1] = WHITE;
	}
	else if (key == 20)
	{
		f->colors[0] = MAROON;
		f->colors[1] = YELLOW;
	}
	else
		color_mode2(key, f);
	fdf(f);
	return (0);
}
