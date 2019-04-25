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

void	init_window(void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	mlx_loop(mlx);
}

int		main(int argc, char const *argv[])
{
	int		fd;

	if (argc != 2)
	{
		ft_printf("{yellow}{b}USAGE: ./fdf [file.fdf]{0}\n");
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("ERROR: Can't open the file.");
	init_window();

	close(fd);
	return (0);
}
