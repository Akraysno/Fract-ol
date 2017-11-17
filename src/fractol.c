/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:00:55 by gauffret          #+#    #+#             */
/*   Updated: 2017/02/02 12:01:09 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_ftl	*init_fract2(t_ftl *ftl, double tmp_zoom)
{
	if (tmp_zoom == ftl->zoom)
	{
		ftl->x1 = ftl->y1;
		ftl->x2 = ftl->y2;
	}
	if (tmp_zoom != ftl->zoom)
	{
		ftl->y1 = ftl->x1;
		ftl->y2 = ftl->x2;
	}
	ftl->sav_x1 = ftl->x1;
	ftl->sav_x2 = ftl->x2;
	ftl->sav_y1 = ftl->y1;
	ftl->sav_y2 = ftl->y2;
	return (ftl);
}

t_ftl	*init_fract(t_var *var)
{
	t_ftl	*ftl;
	double	abs_zoomx;
	double	abs_zoomy;
	double	tmp_zoom;

	ftl = (t_ftl *)malloc(sizeof(t_ftl));
	if (!ftl)
		quit_malloc_error(var, 2);
	ftl->x1 = -2.1;
	ftl->x2 = 2.1;
	ftl->y1 = -1.25;
	ftl->y2 = 1.25;
	var->nb_iter = I_MAX;
	abs_zoomx = (((ftl->x1 < 0) ? (-ftl->x1) : (ftl->x1)) + \
								((ftl->x2 < 0) ? (-ftl->x2) : (ftl->x2)));
	abs_zoomy = (((ftl->y1 < 0) ? (-ftl->y1) : (ftl->y1)) + \
								((ftl->y2 < 0) ? (-ftl->y2) : (ftl->y2)));
	tmp_zoom = var->w_height / abs_zoomy;
	ftl->zoom = var->w_width / abs_zoomx;
	ftl->zoom = ((tmp_zoom > ftl->zoom) ? (ftl->zoom) : (tmp_zoom));
	ftl->sav_zoom = ftl->zoom;
	ftl = init_fract2(ftl, tmp_zoom);
	return (ftl);
}

t_var	*init_var(t_var *var, int id_fract)
{
	var = (t_var *)malloc(sizeof(t_var));
	if (!var)
		quit_malloc_error(var, 1);
	var->move_julia = 1;
	var->auto_key = 0;
	var->w_width = W_WIDTH;
	var->w_height = W_HEIGHT;
	var->ftl = init_fract(var);
	var->mlx = mlx_init();
	var->color = init_color();
	var->width = var->w_width;
	var->opt = 0;
	var->auto_incr = 0;
	var->x = 0.0;
	var->y = 0.0;
	var->cursorx = 0.0;
	var->cursory = 0.0;
	var->x_dec = 0.0;
	var->y_dec = 0.0;
	var->sav_width = var->width;
	var->height = var->w_height;
	var->sav_height = var->height;
	var->id_fract = id_fract;
	var->sound = 1;
	return (var);
}

int		verif_fract(char *str)
{
	int		id_fract;

	id_fract = -1;
	str = ft_strtolower(str);
	if (ft_strcmp(str, "mandelbrot") == 0)
		id_fract = 0;
	if (ft_strcmp(str, "julia") == 0)
		id_fract = 1;
	if (ft_strcmp(str, "cross") == 0)
		id_fract = 2;
	if (ft_strcmp(str, "mandelbar") == 0)
		id_fract = 3;
	if (ft_strcmp(str, "burningship") == 0)
		id_fract = 4;
	if (ft_strcmp(str, "bow") == 0)
		id_fract = 5;
	return (id_fract);
}

int		main(int ac, char **av)
{
	t_var	*var;
	int		index;
	int		id_fract;

	var = NULL;
	index = 1;
	id_fract = -1;
	if (ac > 1)
		id_fract = verif_fract(av[1]);
	if (ac == 1 || (ac != 1 && id_fract == -1))
		quit_no_args();
	var = init_var(var, id_fract);
	recalc_intervalle(var);
	system(AUDIO_ON);
	var->win = mlx_new_window(var->mlx, var->width, var->height, "Fract'ol");
	run_put_map(var);
	mlx_hook(var->win, MOTION_NOTIFY, PTR_MOTION_MASK, ftl_motion_hook, var);
	mlx_hook(var->win, KEY_PRESS, KEY_PRESS_MASK, repeat_key, var);
	mlx_key_hook(var->win, gere_key, var);
	mlx_mouse_hook(var->win, gere_mouse, var);
	mlx_loop(var->mlx);
	return (1);
}
