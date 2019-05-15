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
# define BEIGE		0xF5F5DC
# define DARK_GRAY	0x101010
# define RED		0xFF0000
# define MAROON		0x800000
# define YELLOW		0xFFFF00
# define GINGER		0xEF8E38
# define NAVY		0x000080
# define SKY		0x108DC7
# define SAPPHIRE	0x002661
# define AQUA		0x92FFC0

# define PI			3.1416

typedef struct		s_dots
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_dots;

typedef struct		s_line
{
	int				x;
	int				y;
	int				dx;
	int				dy;
	int				xi;
	int				yi;
	int				d;
	int				s;
	int				e;
	int				s_color;
	int				e_color;
}					t_line;

/*
** VIEW: 0 - iso, 1 - parallel, 5 - auto-rotation
*/

typedef struct		s_fdf
{
	int				w;
	int				h;
	struct s_dots	**map;
	int				*img;
	int				*imarr;
	int				x0;
	int				y0;
	char			view;
	double			zoom;
	int				angle_x;
	int				angle_y;
	int				angle_z;
	double			z_scale;
	int				max_z;
	int				min_z;
	int				colors[2];
	enum {on, off}	controls;
	void			*mlx;
	void			*win;
}					t_fdf;

/*
** main.c
*/

t_fdf				*init_fdf(void);
void				run_mlx(t_fdf *f);
void				fdf(t_fdf *f);

/*
** read.c
*/

char				*read_file(const char *av);
int					get_map_height(char		*file);
int					get_map_width(char		*file);
int					create_map(t_fdf *f);

/*
** validate.c
*/

int					validate(t_fdf *f, char *file);
int					map_z(t_fdf *f, int *ixy, char *file);
void				int_limits(char *file, int i);
int					is_hex(char *file, int *i);

/*
** camera.c
*/

void				view(t_fdf *f);
void				reset_view(t_fdf *f);
int					rotation_mode(t_fdf *f);

/*
** projection.c
*/

void				projection(t_fdf *f);
void				rotate_x(t_fdf *f, int *y, double *z);
void				rotate_y(t_fdf *f, int *x, double *z);
void				rotate_z(t_fdf *f, int *x, int *y);

/*
** draw.c
*/

void				put_pixel(t_fdf *f, struct s_line ln);
void				draw_grid(t_fdf *f);
void				draw_line(t_fdf *f, struct s_dots s, struct s_dots e);
void				line_low(t_fdf *f, struct s_dots s,
							struct s_dots e, struct s_line l);
void				line_high(t_fdf *f, struct s_dots s,
							struct s_dots e, struct s_line l);

/*
** colors.c
*/

void				dots_color(t_fdf *f);
int					get_dots_color(t_fdf *f, int z);
int					get_pixel_color(struct s_line ln);
double				ratio(int cur, int low, int high);
int					light_my_fire(int low, int high, double rat);

/*
** controls.c & controls2.c
*/

int					key_press(int key, t_fdf *f);
int					switch_view(t_fdf *f, int key);
int					scroll(int key, t_fdf *f);
int					zoom(int key, t_fdf *f);
int					rotate(int key, t_fdf *f);
int					z_scale(int key, t_fdf *f);
int					color_mode(int key, t_fdf *f);
void				display_controls(t_fdf *f);

/*
** clean.c
*/

int					exit_fdf(t_fdf *f);
void				fdf_error(char *msg);
void				del_map(t_fdf *f);

///DEBUG
void				print_map(t_fdf *f);

#endif
