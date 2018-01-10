/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:13:00 by kmjaku            #+#    #+#             */
/*   Updated: 2017/03/28 00:14:32 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../mlx/minilibx_macos/mlx.h"
# include <math.h>
# define WIDTH 1800
# define HEIGHT 1250
# define BPP 32
# define DOWN 126
# define UP 125
# define RIGHT 124
# define LEFT 123
# define ZOOM_UP 69
# define ZOOM_DOWN 78
# define R_X_P 84
# define R_X_N 83
# define R_Y_P 87
# define R_Y_N 86
# define R_Z_P 91
# define R_Z_N 89
# define ESC 53
# define RESET 15

typedef struct		s_matrix
{
	double			matrix[4][4];
}					t_matrix;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	double			w;
	int				color;
}					t_point;

typedef struct		s_map
{
	t_point			**point;
}					t_map;

typedef struct		s_data
{
	double			dx;
	double			dy;
	double			flag;
	double			ternx;
	double			terny;
	char			*pixel;
	int				endian;
	int				bpp;
	double			x_start;
	double			y_start;
	double			x_center;
	double			y_center;
	void			*mlx;
	void			*win;
	void			*img;
	char			**g_map;
	int				size_line;
	int				width_map;
	int				height_map;
	char			*ptr;
	char			*str;
	int				fd;
	double			zoom;
	t_map			*save;
	t_map			*map;
	t_point			*point;
	t_matrix		*m;
}					t_data;

void				usage(void);
int					get_col_nb(char **str);
void				ft_free_tab(char **tab);
void				draw_line(t_point p0, t_point p1, t_data *data);
int					ft_palete(t_point p0, t_point p1);
void				put_isometric(t_data *data);
int					key_hook(int key, t_data *data);
void				move_right_left(int key, t_data *data);
void				move_up_down(int key, t_data *data);
void				zoom_up_down(int key, t_data *data);
void				event_rotate_x(int key, t_data *data);
void				event_rotate_y(int key, t_data *data);
void				event_rotate_z(int key, t_data *data);
void				event_esc(int key, t_data *data);
int					set_image(t_data *data);
void				init_env(t_data *data);
t_matrix			rotate_z(double z);
t_matrix			rotate_y(double y);
t_matrix			rotate_x(double x);
t_matrix			scale(double sx, double sy, double sz);
void				all_points(t_data *data, t_matrix *m);
t_matrix			translate(double tx, double ty, double tz);
void				draw_map(t_data *data);
t_matrix			matrix_void(void);
void				get_point(t_data **data, char *file);
void				malloc_point(t_data **data);
void				error_exit(char *str);
void				error_alloc(void);

#endif
