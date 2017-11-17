/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 11:48:27 by gauffret          #+#    #+#             */
/*   Updated: 2017/05/19 11:48:32 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

double	*coor_center_fract(t_var *var, double *inter)
{
	double	*coor;
	double	midx;
	double	midy;

	coor = (double *)malloc(sizeof(double) * 2);
	if (!coor)
		quit_malloc_error(var, 3);
	midx = (inter[0] / 2) - var->ftl->x2;
	midy = (inter[1] / 2) - var->ftl->y2;
	coor[0] = midx;
	coor[1] = midy;
	return (coor);
}

void	recalc_intervalle(t_var *var)
{
	double		ratiox;
	double		ratioy;
	double		interx;
	double		intery;

	ratiox = (fabs(var->ftl->x1) + fabs(var->ftl->x2)) / var->width;
	ratioy = (fabs(var->ftl->y1) + fabs(var->ftl->y2)) / var->height;
	if (ratiox > ratioy)
	{
		interx = var->width * ratioy;
		var->ftl->x1 = -(interx / 2);
		var->ftl->x2 = interx / 2;
	}
	else if (ratiox < ratioy)
	{
		intery = var->height * ratiox;
		var->ftl->y1 = -(intery / 2);
		var->ftl->y2 = intery / 2;
	}
}
