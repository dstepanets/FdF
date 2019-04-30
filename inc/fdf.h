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
# include <math.h>

# define WIN_W		1280
# define WIN_H 		720

# define WHITE		0xFFFFFF
# define BLACK		0x000000
# define DARK_GRAY	0x101010
# define GRAY		0x424242
# define RED		0xFF0000
# define MAROON		0x800000	
# define GREEN		0x008000
# define LIME		0x00FF00
# define BLUE		0x0000FF
# define NAVY		0x000080
# define YELLOW		0xFFFF00



typedef struct			s_dots
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_dots;

typedef struct			s_line
{
	int					x1;
	int					y1;
	int					x2;
	int					y2;

}						t_line;

typedef struct			s_fdf
{
	int					h;
	int					w;
	struct s_dots		**map;
	void				*mlx;
	void				*win;
	struct s_line		*ln;
}						t_fdf;

char			*read_file(const char *av);
int				get_map_height(char		*file);
int				get_map_width(char		*file);
int				create_map(t_fdf *f);
int				populate_map(t_fdf *f, char *file);

void			draw_line(t_fdf *f);

int				exit_fdf(t_fdf *f);
void			fdf_error(char *msg);
void			del_map(t_fdf *f);

///DEBUG
void			print_map(t_fdf *f);

#endif