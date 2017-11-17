/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:59:02 by gauffret          #+#    #+#             */
/*   Updated: 2017/05/19 12:59:03 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static double	*key_coor_center_fract(t_var *var, double interx, double intery)
{
	double	*coor;
	double	midx;
	double	midy;

	coor = (double *)malloc(sizeof(double) * 2);
	midx = (interx / 2) - var->ftl->x2;
	midy = (intery / 2) - var->ftl->y2;
	coor[0] = midx;
	coor[1] = midy;
	return (coor);
}

void			key_zoom(t_var *var, int key)
{
	double interx;
	double intery;
	double tmp_zoom;
	double *coor;
	double multi;

	interx = var->ftl->x2 - var->ftl->x1;
	interx = fabs(interx);
	intery = var->ftl->y2 - var->ftl->y1;
	intery = fabs(intery);
	coor = key_coor_center_fract(var, interx, intery);
	if (!coor)
		quit_malloc_error(var, 3);
	multi = ((key == 78) ? (1.1) : (1));
	multi = ((key == 69) ? (0.9) : (multi));
	var->ftl->x1 = 0 - (interx * multi / 2) - coor[0];
	var->ftl->x2 = 0 + (interx * multi / 2) - coor[0];
	var->ftl->y1 = 0 - (intery * multi / 2) - coor[1];
	var->ftl->y2 = 0 + (intery * multi / 2) - coor[1];
	tmp_zoom = var->height / (intery * multi);
	var->ftl->zoom = var->width / (interx * multi);
	var->ftl->zoom = ((tmp_zoom < var->ftl->zoom) ? (tmp_zoom) : \
														(var->ftl->zoom));
	var->nb_iter += ((var->auto_incr) ? (1) : (0));
	run_put_map(var);
}

void			move_screen2(t_var *var, int action, double interx, \
																double intery)
{
	if (action == 1)
	{
		var->ftl->x1 -= interx * 1 / 10;
		var->ftl->x2 -= interx * 1 / 10;
	}
	if (action == 2)
	{
		var->ftl->x1 += interx * 1 / 10;
		var->ftl->x2 += interx * 1 / 10;
	}
	if (action == 3)
	{
		var->ftl->y1 += intery * 1 / 10;
		var->ftl->y2 += intery * 1 / 10;
	}
	if (action == 4)
	{
		var->ftl->y1 -= intery * 1 / 10;
		var->ftl->y2 -= intery * 1 / 10;
	}
}

void			move_screen(t_var *var, int action)
{
	double	interx;
	double	intery;

	if (var->ftl->x2 >= 0 && var->ftl->x1 <= 0)
		interx = fabs(var->ftl->x2) + fabs(var->ftl->x1);
	if (var->ftl->x2 > 0 && var->ftl->x1 > 0)
		interx = var->ftl->x2 - var->ftl->x1;
	if (var->ftl->x2 < 0 && var->ftl->x1 < 0)
		interx = fabs(var->ftl->x1) - fabs(var->ftl->x2);
	if (var->ftl->y2 >= 0 && var->ftl->y1 <= 0)
		intery = fabs(var->ftl->y2) + fabs(var->ftl->y1);
	if (var->ftl->y2 > 0 && var->ftl->y1 > 0)
		intery = var->ftl->y2 - var->ftl->y1;
	if (var->ftl->y2 < 0 && var->ftl->y1 < 0)
		intery = fabs(var->ftl->y1) - fabs(var->ftl->y2);
	move_screen2(var, action, interx, intery);
}
