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

# define WIN_W		1444
# define WIN_H 		1024

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
	int					x;
	int					y;
	int					dx;
	int					dy;
	int					xi;
	int					yi;
	int					d;

}						t_line;

/*
** VIEW: 0 - parallel, 1 - iso;
*/

typedef struct			s_fdf
{
	int					w;
	int					h;
	struct s_dots		**map;

	int					x0;
	int					y0;
	int					grid_step;
	char				view;
	double				zoom;
	double				angle_x;
	double				angle_y;
	double				angle_z;

	void				*mlx;
	void				*win;
}						t_fdf;

t_fdf			*init_fdf(void);
char			*read_file(const char *av);
int				get_map_height(char		*file);
int				get_map_width(char		*file);
int				create_map(t_fdf *f);
int				map_z(t_fdf *f, char *file);

void			run_mlx(t_fdf *f);
void			fdf(t_fdf *f);
void			reset_fdf(t_fdf *f);

int				key_press(int key, t_fdf *f);
int				switch_view(int key, t_fdf *f);
int				scroll(int key, t_fdf *f);
int				zoom(int key, t_fdf *f);
int				rotate_controls(int key, t_fdf *f);

void			draw_grid(t_fdf *f);
void			draw_line(t_fdf *f, struct s_dots s, struct s_dots e);
void			line_low(t_fdf *f, struct s_dots s, struct s_dots e);
void			line_high(t_fdf *f, struct s_dots s, struct s_dots e);

void			view(t_fdf *f);
void			parallel(t_fdf *f);
void			to_isometric(t_fdf *f);
void			iso(int *x, int *y, int z);

void			rotate(t_fdf *f);
void			rotate_x(t_fdf *f, int *y, int *z);
void			rotate_y(t_fdf *f, int *x, int *z);
void			rotate_z(t_fdf *f, int *x, int *y);

int				exit_fdf(t_fdf *f);
void			fdf_error(char *msg);
void			del_map(t_fdf *f);

///DEBUG
void			print_map(t_fdf *f);

#endif