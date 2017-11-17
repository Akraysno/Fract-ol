/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:26:59 by gauffret          #+#    #+#             */
/*   Updated: 2017/05/10 10:27:07 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		ftl_motion_hook(int x, int y, t_var *var)
{
	if ((var->move_julia && (var->id_fract == 1 || var->id_fract == 2\
												|| var->id_fract == 5)))
	{
		var->cursorx = (double)x / (double)var->width * 4 - 2;
		var->cursory = (double)y / (double)var->height * 4 - 2;
		run_put_map(var);
	}
	return (0);
}

double	ratio_x_calc(t_var *var, int d_x, int interx)
{
	double ratio;

	(void)var;
	ratio = d_x / interx;
	return (ratio);
}

double	ratio_y_calc(t_var *var, int d_y, int intery)
{
	double ratio;

	(void)var;
	ratio = d_y / intery;
	return (ratio);
}

void	gere_mouse2(t_var *var, double *coor, double multi, double *inter)
{
	var->ftl->zoom = var->width / (inter[0] * multi);
	var->ftl->zoom = (((var->height / (inter[1] * multi)) < \
	var->ftl->zoom) ? ((var->height / (inter[1] * multi))) : (var->ftl->zoom));
	var->nb_iter += ((var->auto_incr) ? (1) : (0));
	ft_memdel((void **)&coor);
	run_put_map(var);
}

int		gere_mouse(int code, int x, int y, t_var *var)
{
	double	inter[2];
	double	p[2];
	double	*coor;
	double	multi;

	if ((x >= 0 && y >= 0) && ((var->id_fract == 0 || var->id_fract == 3 \
		|| var->id_fract == 4) || ((var->id_fract == 1 \
		|| var->id_fract == 2 || var->id_fract == 5) && !var->move_julia)))
	{
		p[0] = ((x - (var->width / 2)) / var->ftl->zoom);
		p[1] = ((y - (var->height / 2)) / var->ftl->zoom);
		inter[0] = fabs(var->ftl->x2 - var->ftl->x1);
		inter[1] = fabs(var->ftl->y2 - var->ftl->y1);
		coor = coor_center_fract(var, inter);
		if (!coor)
			quit_malloc_error(var, 3);
		multi = ((code == 1 || code == 5) ? (0.9) : (1));
		multi = ((code == 2 || code == 4) ? (1.1) : (multi));
		var->ftl->x1 = p[0] - (inter[0] * multi / 2) - coor[0];
		var->ftl->x2 = p[0] + (inter[0] * multi / 2) - coor[0];
		var->ftl->y1 = p[1] - (inter[1] * multi / 2) - coor[1];
		var->ftl->y2 = p[1] + (inter[1] * multi / 2) - coor[1];
		gere_mouse2(var, coor, multi, inter);
	}
	return (1);
}
