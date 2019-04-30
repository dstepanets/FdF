/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:59:19 by dstepane          #+#    #+#             */
/*   Updated: 2019/04/26 19:59:21 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int			exit_fdf(t_fdf *f)
{
	del_map(f);
	free(f);
		printf("\n#################################################\n");		///
		system("leaks -q fdf");		///
	exit(0);
	return (0);
}

void			fdf_error(char *msg)
{
	ft_printf("{red}{b}%s{0}\n", msg);
		printf("\n#################################################\n");		///
		system("leaks -q fdf");		///
	exit(0);
}

void			del_map(t_fdf *f)
{
	int		y;

	y = 0;
	while (y < f->h)
		free(f->map[y++]);
	free(f->map[y]);
	free(f->map);
}
