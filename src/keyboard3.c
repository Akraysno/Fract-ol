/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 13:08:31 by gauffret          #+#    #+#             */
/*   Updated: 2017/05/19 13:08:32 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	key_corr(t_var *var)
{
	double interx;
	double intery;
	double tmp_zoom;
	double coor[2];

	interx = var->ftl->x2 - var->ftl->x1;
	interx = fabs(interx);
	intery = var->ftl->y2 - var->ftl->y1;
	intery = fabs(intery);
	coor[0] = (interx / 2) - var->ftl->x2;
	coor[1] = (intery / 2) - var->ftl->y2;
	var->ftl->x1 = -(interx / 2) - coor[0];
	var->ftl->x2 = (interx / 2) - coor[0];
	var->ftl->y1 = -(intery / 2) - coor[1];
	var->ftl->y2 = (intery / 2) - coor[1];
	tmp_zoom = var->height / intery;
	var->ftl->zoom = var->width / interx;
	var->ftl->zoom = ((tmp_zoom < var->ftl->zoom) ? (tmp_zoom) : \
													(var->ftl->zoom));
}

static void	modif_window2(t_var *var, int key, double ratiox, double ratioy)
{
	if (key == 87)
	{
		var->width = var->sav_width;
		var->height = var->sav_height;
		ratioy = (((var->ftl->y1 < 0) ? (-var->ftl->y1) : (var->ftl->y1)) + \
				((var->ftl->y2 < 0) ? (-var->ftl->y2) : (var->ftl->y2)));
		ratiox = var->height / ratioy;
		var->ftl->zoom = ratiox;
	}
	if (var->mlx && var->win)
	{
		mlx_clear_window(var->mlx, var->win);
		mlx_destroy_window(var->mlx, var->win);
	}
	key_corr(var);
	var->win = mlx_new_window(var->mlx, var->width, var->height, "Fract'ol");
	run_put_map(var);
	mlx_hook(var->win, MOTION_NOTIFY, PTR_MOTION_MASK, ftl_motion_hook, var);
	mlx_hook(var->win, KEY_PRESS, KEY_PRESS_MASK, repeat_key, var);
	mlx_key_hook(var->win, gere_key, var);
	mlx_mouse_hook(var->win, gere_mouse, var);
	mlx_loop(var->mlx);
}

void		modif_window(int key, t_var *var)
{
	double ratiox;
	double ratioy;

	if (key == 83 && (var->height - 100 > 500) && (var->width - 100 > 500))
	{
		var->height -= 100;
		var->width -= 100;
		ratioy = (((var->ftl->y1 < 0) ? (-var->ftl->y1) : (var->ftl->y1)) + \
					((var->ftl->y2 < 0) ? (-var->ftl->y2) : (var->ftl->y2)));
		ratiox = var->height / ratioy;
		var->ftl->zoom = ((ratiox > var->ftl->zoom) ? \
												(var->ftl->zoom) : (ratiox));
	}
	if (key == 92 && (var->height - 100 < 1000) && (var->width - 100 < 1000))
	{
		var->height += 100;
		var->width += 100;
		ratioy = (((var->ftl->y1 < 0) ? (-var->ftl->y1) : (var->ftl->y1)) + \
					((var->ftl->y2 < 0) ? (-var->ftl->y2) : (var->ftl->y2)));
		ratiox = var->height / ratioy;
		var->ftl->zoom = ((ratiox < var->ftl->zoom) ? \
									(var->ftl->zoom) : (ratiox));
	}
	modif_window2(var, key, ratiox, ratioy);
}
