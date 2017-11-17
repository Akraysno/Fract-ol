/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:13:14 by gauffret          #+#    #+#             */
/*   Updated: 2017/05/10 10:13:15 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	draw_mandelbar(t_var *var, double tmp, int x, int y)
{
	int		i;
	double	z_r;
	double	z_i;
	double	c_r;
	double	c_i;

	c_r = x / ((var->ftl->zoom) ? (var->ftl->zoom) : (1)) + var->ftl->x1;
	c_i = y / ((var->ftl->zoom) ? (var->ftl->zoom) : (1)) + var->ftl->y1;
	z_r = c_r;
	z_i = c_i;
	i = 1;
	while (z_r * z_r + z_i * z_i < 10.0 && i < var->nb_iter)
	{
		tmp = z_r;
		z_i *= -1;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2.0 * z_i * tmp + c_i;
		i = i + 1;
	}
	*(unsigned *)(var->img->img_data + lrint(y * var->width * \
									4.0) + lrint(x * 4.0)) = get_color(var, i);
}
