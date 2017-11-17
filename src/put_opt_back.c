/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_opt_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:11:32 by gauffret          #+#    #+#             */
/*   Updated: 2017/05/10 16:11:34 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	put_back_fract(t_var *var)
{
	int		x;
	int		y;
	int		color;

	color = mlx_get_color_value(var->mlx, 0x00111111);
	x = 0;
	y = 0;
	while (y < 155)
	{
		while (x < 230)
		{
			*(unsigned *)(var->img->img_data + (y * var->width * 4) + \
														(x * 4)) = color;
			x++;
		}
		x = 0;
		y++;
	}
}

static void	put_back_bornes(t_var *var)
{
	int		x;
	int		y;
	int		color;

	x = var->width - 260;
	y = var->height - 115;
	color = mlx_get_color_value(var->mlx, 0x00111111);
	while (y < var->height)
	{
		while (x < var->width)
		{
			*(unsigned *)(var->img->img_data + (y * var->width * 4) + \
														(x * 4)) = color;
			x++;
		}
		x = var->width - 260;
		y++;
	}
}

static void	put_back_iter(t_var *var)
{
	int		x;
	int		y;
	int		color;

	color = mlx_get_color_value(var->mlx, 0x00111111);
	y = var->height - 76;
	if (var->id_fract == 1 || var->id_fract == 2 || var->id_fract == 5)
		y -= 60;
	while (++y < var->height)
	{
		x = -1;
		while (++x < 350)
			*(unsigned *)(var->img->img_data + (y * var->width * 4) + \
														(x * 4)) = color;
	}
	color = mlx_get_color_value(var->mlx, 0x00FF0000);
	y = var->height - 51;
	while (++y < var->height - 30)
	{
		x = 310;
		while (++x < 320)
			*(unsigned *)(var->img->img_data + (y * var->width * 4) + \
														(x * 4)) = color;
	}
}

void		put_opt_back(t_var *var)
{
	int		x;
	int		y;
	int		color;

	color = mlx_get_color_value(var->mlx, 0x00111111);
	put_back_bornes(var);
	put_back_iter(var);
	put_back_fract(var);
	x = var->width - 255;
	y = -1;
	while (y < 275)
	{
		while (x < var->width)
		{
			*(unsigned *)(var->img->img_data + (y * var->width * 4) + \
															(x * 4)) = color;
			x++;
		}
		x = var->width - 255;
		y++;
	}
}
