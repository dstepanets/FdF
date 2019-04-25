/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:16:58 by dstepane          #+#    #+#             */
/*   Updated: 2019/04/25 19:16:59 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	error(char *msg)
{
	ft_printf("{red}{b}%s{0}\n", msg);
	exit(0);
}

int		main(int argc, char const *argv[])
{
	int		fd;

	if (argc != 2)
	{
		ft_printf("{yellow}{b}USAGE: ./fdf [input_file]{0}\n");
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("ERROR: Can't open the file.");

	close(fd);
	return (0);
}
