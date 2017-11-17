/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:41:04 by gauffret          #+#    #+#             */
/*   Updated: 2017/05/10 10:41:05 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		change_fract(t_var *var, int key)
{
	if (key == 18 && var->id_fract != 0)
		var->id_fract = 0;
	if (key == 19 && var->id_fract != 1)
		var->id_fract = 1;
	if (key == 20 && var->id_fract != 2)
		var->id_fract = 2;
	if (key == 21 && var->id_fract != 3)
		var->id_fract = 3;
	if (key == 23 && var->id_fract != 4)
		var->id_fract = 4;
	if (key == 22 && var->id_fract != 5)
		var->id_fract = 5;
}

void		reset(int key, t_var *var)
{
	var->ftl->x1 = var->ftl->sav_x1;
	var->ftl->x2 = var->ftl->sav_x2;
	var->ftl->y1 = var->ftl->sav_y1;
	var->ftl->y2 = var->ftl->sav_y2;
	var->ftl->zoom = var->ftl->sav_zoom;
	var->nb_iter = I_MAX;
	var->x = 0;
	var->y = 0;
	var->ftl->zoom = var->height / (((var->ftl->y1 < 0) ? (-var->ftl->y1) : \
	(var->ftl->y1)) + ((var->ftl->y2 < 0) ? (-var->ftl->y2) : (var->ftl->y2)));
	recalc_intervalle(var);
	change_fract(var, key);
}

static void	gere_key2(int key, t_var *var)
{
	if (key == 29 || key == 25 || key == 50 || key == 48)
	{
		if (key == 29)
			var->color->use_color = 1;
		if (key == 25)
			var->color->use_color = 0;
		if (key == 50)
			var->opt = ((var->opt) ? (0) : (1));
		if (key == 48)
			var->move_julia = ((var->move_julia) ? (0) : (1));
		run_put_map(var);
	}
}

int			gere_key(int key, t_var *var)
{
	if (key == 53)
		quit(var);
	if (key == 261)
	{
		var->sound = !var->sound;
		system(AUDIO_OFF);
		if (var->sound)
			system(AUDIO_ON);
	}
	if (key == 71 || key == 18 || key == 19 || key == 20 || key == 21 || \
		key == 23 || key == 22)
	{
		reset(key, var);
		run_put_map(var);
	}
	if (key == 113)
		var->nb_iter += 50;
	if (key == 113)
		run_put_map(var);
	if (key == 115)
		var->auto_incr = ((var->auto_incr) ? (0) : (1));
	if (key == 87 || key == 92 || key == 83)
		modif_window(key, var);
	gere_key2(key, var);
	return (1);
}

int			repeat_key(int key, t_var *var)
{
	if ((key == 78 || key == 69) && (((var->id_fract == 1 || \
		var->id_fract == 2) && !var->move_julia) || (var->id_fract == 0 \
		|| var->id_fract == 3 || var->id_fract == 4 || var->id_fract == 5)))
		key_zoom(var, key);
	if (key == 116 || (key == 121 && var->nb_iter != 0) || key == 123 || \
		(key == 31 && var->color->use_color == 0) || key == 124 || \
		(key == 35 && var->color->use_color == 0) || key == 125 || key == 126)
	{
		if (key == 116)
			var->nb_iter += 1;
		if (key == 121)
			var->nb_iter -= 1;
		if (key == 31 && var->color->use_color == 0)
			var->color->index++;
		if (key == 35 && var->color->use_color == 0)
			var->color->index--;
		if (key == 123 || key == 124 || key == 125 || key == 126)
			move_screen(var, key - 122);
		if (var->color->index < 0)
			var->color->index = 25;
		if (var->color->index > 25)
			var->color->index = 0;
		run_put_map(var);
	}
	return (1);
}
