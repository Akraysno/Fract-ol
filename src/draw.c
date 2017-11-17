/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:33:06 by gauffret          #+#    #+#             */
/*   Updated: 2017/05/10 10:33:07 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	draw_center(t_var *var)
{
	int i;
	int j;
	int	i_mid;
	int j_mid;
	int	color;

	i = -1;
	j = -1;
	i_mid = var->width / 2;
	j_mid = var->height / 2;
	color = mlx_get_color_value(var->mlx, 0x00FFFFFF);
	while (++i < var->width)
		if (i > (i_mid - (var->width / 100)) && \
			i < (i_mid + (var->width / 100)))
			*(unsigned *)(var->img->img_data + lrint(j_mid * \
								var->width * 4.0) + lrint(i * 4.0)) = color;
	while (++j < var->height)
		if (j > (j_mid - (var->height / 100)) && \
			j < (j_mid + (var->height / 100)))
			*(unsigned *)(var->img->img_data + lrint(j * var->width * 4.0) + \
											lrint(i_mid * 4.0)) = color;
}

void	draw_thread_fract(t_var *var, int x, int y)
{
	if (var->id_fract == 0)
		draw_mandelbrot(var, 0.0, x, y);
	if (var->id_fract == 1)
		draw_julia(var, 0.0, x, y);
	if (var->id_fract == 2)
		draw_cross(var, 0.0, x, y);
	if (var->id_fract == 3)
		draw_mandelbar(var, 0.0, x, y);
	if (var->id_fract == 4)
		draw_burning_ship(var, 0.0, x, y);
	if (var->id_fract == 5)
		draw_bow(var, x, y, 0.0);
}

void	draw_fract(t_var *var)
{
	pthread_t tid1;
	pthread_t tid2;
	pthread_t tid3;
	pthread_t tid4;

	var->img = create_image(var, var->width, var->height);
	pthread_create(&tid1, NULL, draw_thread1, var);
	pthread_create(&tid2, NULL, draw_thread2, var);
	pthread_create(&tid3, NULL, draw_thread3, var);
	pthread_create(&tid4, NULL, draw_thread4, var);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);
	pthread_join(tid4, NULL);
}
