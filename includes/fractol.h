/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:59:49 by gauffret          #+#    #+#             */
/*   Updated: 2017/02/02 12:00:46 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <openGL/gl.h>
# include <stdio.h>
# include <pthread.h>
# include "/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h"

# define AUDIO_ON	"afplay ./resources/Nyan_Cat.mp3 &>/dev/null &"
# define AUDIO_OFF	"killall afplay &>/dev/null"
# define W_WIDTH 800
# define W_HEIGHT 800
# define COLOR 0x00CBA321
# define I_MAX 35
# define ADD_ZOOM 200

# define PTR_MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6
# define KEY_PRESS_MASK (1L<<0)
# define KEY_PRESS 2

typedef struct		s_color
{
	int				index;
	int				*color;
	int				use_color;
}					t_clr;

typedef struct		s_img
{
	void			*img;
	char			*img_data;
	int				nb_bits;
	int				len_line;
	int				endian;
}					t_img;

typedef struct		s_ftl
{
	double			zoom;
	double			sav_zoom;
	double			x1;
	double			sav_x1;
	double			x2;
	double			sav_x2;
	double			y1;
	double			sav_y1;
	double			y2;
	double			sav_y2;
	double			z_r;
	double			c_r;
	double			z_i;
	double			c_i;
}					t_ftl;

typedef struct		s_var
{
	void			*mlx;
	void			*win;
	int				w_width;
	int				width;
	int				sav_width;
	int				w_height;
	int				height;
	int				sav_height;
	double			x_dec;
	double			y_dec;
	double			x;
	double			y;
	double			cursorx;
	double			cursory;
	int				nb_iter;
	int				opt;
	int				auto_incr;
	int				id_fract;
	int				move_julia;
	int				auto_key;
	int				sound;
	struct s_img	*img;
	struct s_ftl	*ftl;
	struct s_color	*color;
}					t_var;

void				draw_mandelbrot(t_var *var, double tmp, int x, int y);
void				draw_mandelbar(t_var *var, double tmp, int x, int y);
void				draw_julia(t_var *var, double tmp, int x, int y);
void				draw_bow(t_var *var, int x, int y, double tmp);
void				draw_burning_ship(t_var *var, double tmp, int x, int y);
void				draw_cross(t_var *var, double tmp, int x, int y);
void				draw_fract(t_var *var);
void				draw_center(t_var *var);
void				put_opt_back(t_var *var);
void				put_opt(t_var *var);
void				recalc_intervalle(t_var *var);
void				modif_window(int key, t_var *var);
int					ftl_motion_hook(int x, int y, t_var *var);
int					gere_mouse(int code, int x, int y, t_var *var);
int					gere_key(int key, t_var *var);
int					repeat_key(int key, t_var *var);
void				reset(int key, t_var *var);
void				change_fract(t_var *var, int key);
void				key_zoom(t_var *var, int key);
int					get_color(t_var *var, int i);
t_clr				*init_color(void);
void				draw_fract(t_var *var);
void				draw_center(t_var *var);
void				*draw_thread1(void *v);
void				*draw_thread2(void *v);
void				*draw_thread3(void *v);
void				*draw_thread4(void *v);
void				draw_thread_fract(t_var *var, int x, int y);
void				move_screen(t_var *var, int action);
double				*coor_center_fract(t_var *var, double *inter);
t_img				*create_image(t_var *var, long int x, long int y);
t_ftl				*init_fract(t_var *var);
void				run_put_map(t_var *var);
void				quit_no_args(void);
void				quit_malloc_error(t_var *var, int err);
void				quit(t_var *var);

#endif
