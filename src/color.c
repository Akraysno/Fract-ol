/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:28:33 by gauffret          #+#    #+#             */
/*   Updated: 2017/05/10 10:28:34 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int		get_color3(t_var *var, int i, int index, int color)
{
	if (i < var->nb_iter * 25 / 100)
		color = var->color->color[(index + 15) % 25];
	if (i < var->nb_iter * 20 / 100)
		color = var->color->color[(index + 16) % 25];
	if (i < var->nb_iter * 15 / 100)
		color = var->color->color[(index + 17) % 25];
	if (i < var->nb_iter * 10 / 100)
		color = var->color->color[(index + 18) % 25];
	if (i < var->nb_iter * 05 / 100)
		color = var->color->color[(index + 19) % 25];
	if (i == 1)
		color = 0;
	return (color);
}

static int		get_color2(t_var *var, int i, int index, int color)
{
	if (i < var->nb_iter * 80 / 100)
		color = var->color->color[(index + 4) % 25];
	if (i < var->nb_iter * 75 / 100)
		color = var->color->color[(index + 5) % 25];
	if (i < var->nb_iter * 70 / 100)
		color = var->color->color[(index + 6) % 25];
	if (i < var->nb_iter * 65 / 100)
		color = var->color->color[(index + 7) % 25];
	if (i < var->nb_iter * 60 / 100)
		color = var->color->color[(index + 8) % 25];
	if (i < var->nb_iter * 55 / 100)
		color = var->color->color[(index + 9) % 25];
	if (i < var->nb_iter * 50 / 100)
		color = var->color->color[(index + 10) % 25];
	if (i < var->nb_iter * 45 / 100)
		color = var->color->color[(index + 11) % 25];
	if (i < var->nb_iter * 40 / 100)
		color = var->color->color[(index + 12) % 25];
	if (i < var->nb_iter * 35 / 100)
		color = var->color->color[(index + 13) % 25];
	if (i < var->nb_iter * 30 / 100)
		color = var->color->color[(index + 14) % 25];
	color = get_color3(var, i, index, color);
	return (color);
}

int				get_color(t_var *var, int i)
{
	int		color;
	int		index;

	if (var->color->use_color == 1)
	{
		if (i == var->nb_iter)
			color = mlx_get_color_value(var->mlx, COLOR);
		else
			color = mlx_get_color_value(var->mlx, (i * 255 / I_MAX) * i * i);
	}
	else
	{
		index = var->color->index;
		color = 0x00000000;
		if (i == var->nb_iter)
			color = var->color->color[index];
		if (i < var->nb_iter * 95 / 100)
			color = var->color->color[(index + 1) % 25];
		if (i < var->nb_iter * 90 / 100)
			color = var->color->color[(index + 2) % 25];
		if (i < var->nb_iter * 85 / 100)
			color = var->color->color[(index + 3) % 25];
		color = get_color2(var, i, index, color);
	}
	return (color);
}

static t_clr	*init_color2(t_clr *color)
{
	color->color[15] = 0x00FFBA33;
	color->color[16] = 0x00FF9933;
	color->color[17] = 0x00FF6615;
	color->color[18] = 0x00FF3300;
	color->color[19] = 0x00FF3333;
	color->color[20] = 0x00FF3366;
	color->color[21] = 0x00CC1566;
	color->color[22] = 0x00990066;
	color->color[23] = 0x00750045;
	color->color[24] = 0x00500033;
	color->color[25] = 0x00420042;
	return (color);
}

t_clr			*init_color(void)
{
	t_clr	*color;

	color = (t_clr *)malloc(sizeof(t_clr));
	color->index = 0;
	color->use_color = 0;
	color->color = (int *)malloc(sizeof(int) * 26);
	color->color[0] = 0x00330066;
	color->color[1] = 0x00331599;
	color->color[2] = 0x00333399;
	color->color[3] = 0x003366CC;
	color->color[4] = 0x003399FF;
	color->color[5] = 0x003399CC;
	color->color[6] = 0x00339999;
	color->color[7] = 0x00339966;
	color->color[8] = 0x00339933;
	color->color[9] = 0x0066BA33;
	color->color[10] = 0x0099CC33;
	color->color[11] = 0x00CDDE33;
	color->color[12] = 0x00FFFF33;
	color->color[13] = 0x00FFDE33;
	color->color[14] = 0x00FFCC33;
	color = init_color2(color);
	return (color);
}
