/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:16:03 by dstepane          #+#    #+#             */
/*   Updated: 2019/04/25 19:16:04 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <fcntl.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

typedef struct			s_dots
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_dots;

typedef struct			s_fdf
{
	int					h;
	int					w;
	struct s_dots		**map;
	void				*mlx;
	void				*win;

}						t_fdf;

char			*read_file(const char *av);
int				get_map_height(char		*file);
int				get_map_width(char		*file);
int				create_map(t_fdf *f);
int				populate_map(t_fdf *f, char *file);

void			fdf_error(char *msg);
void			del_map(t_fdf *f);

///DEBUG
void			print_map(t_fdf *f);

#endif