/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:14:17 by gauffret          #+#    #+#             */
/*   Updated: 2017/05/10 10:14:19 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	draw_cross(t_var *var, double tmp, int x, int y)
{
	int		i;
	double	z_r;
	double	z_i;
	double	c_r;
	double	c_i;

	z_r = x / ((var->ftl->zoom) ? (var->ftl->zoom) : (1)) + var->ftl->x1;
	z_i = y / ((var->ftl->zoom) ? (var->ftl->zoom) : (1)) + var->ftl->y1;
	c_r = var->cursorx;
	c_i = var->cursory;
	i = 1;
	while (z_r * z_r + z_i * z_i < 10.0 && i < var->nb_iter)
	{
		tmp = z_r;
		z_r *= -0.5;
		z_i *= 0.7;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2.0 * z_i * tmp + c_i;
		i = i + 1;
	}
	*(unsigned *)(var->img->img_data + lrint(y * var->width * 4.0) + \
									lrint(x * 4.0)) = get_color(var, i);
}
