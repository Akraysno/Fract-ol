/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 13:19:17 by gauffret          #+#    #+#             */
/*   Updated: 2017/05/19 13:19:18 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	*draw_thread1(void *v)
{
	int		x;
	int		y;
	t_var	*var;

	var = (t_var *)v;
	x = -1;
	y = -1;
	while (++x < (var->width / 2) + 1)
	{
		while (++y < (var->height / 2) + 1)
			draw_thread_fract(var, x, y);
		y = -1;
	}
	return (NULL);
}

void	*draw_thread2(void *v)
{
	int		x;
	int		y;
	t_var	*var;

	var = (t_var *)v;
	x = (var->width / 2) - 1;
	y = -1;
	while (++x < var->width)
	{
		while (++y < (var->height / 2) + 1)
			draw_thread_fract(var, x, y);
		y = -1;
	}
	return (NULL);
}

void	*draw_thread3(void *v)
{
	int		x;
	int		y;
	t_var	*var;

	var = (t_var *)v;
	x = -1;
	y = (var->height / 2) - 1;
	while (++x < (var->width / 2) + 1)
	{
		while (++y < var->height)
			draw_thread_fract(var, x, y);
		y = (var->height / 2) - 1;
	}
	return (NULL);
}

void	*draw_thread4(void *v)
{
	int		x;
	int		y;
	t_var	*var;

	var = (t_var *)v;
	y = (var->height / 2) - 1;
	x = (var->width / 2) - 1;
	while (++x < var->width)
	{
		while (++y < var->height)
			draw_thread_fract(var, x, y);
		y = (var->height / 2) - 1;
	}
	return (NULL);
}
