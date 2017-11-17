/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:38:49 by gauffret          #+#    #+#             */
/*   Updated: 2017/05/10 10:38:53 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	quit_malloc_error(t_var *var, int err)
{
	ft_putstr_fd("./fractol : malloc error.\n", 2);
	system(AUDIO_OFF);
	if (err == 3)
	{
		ft_memdel((void **)&var->ftl);
		ft_memdel((void **)&var->img);
		ft_memdel((void **)&var->color);
		if (var->mlx && var->win)
		{
			mlx_clear_window(var->mlx, var->win);
			mlx_destroy_window(var->mlx, var->win);
		}
	}
	if (err == 2 || err == 3)
		ft_memdel((void **)&var);
	exit(1);
}

t_img	*create_image(t_var *var, long int x, long int y)
{
	t_img	*img;
	int		nb_bits;
	int		len_line;
	int		endian;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		quit_malloc_error(var, 3);
	img->nb_bits = 24;
	nb_bits = 24;
	img->len_line = var->w_height;
	len_line = var->w_height;
	img->endian = 1;
	endian = 1;
	img->img = mlx_new_image(var->mlx, x, y);
	img->img_data = mlx_get_data_addr(img->img, &nb_bits, &len_line, &endian);
	return (img);
}

void	run_put_map(t_var *var)
{
	draw_fract(var);
	draw_center(var);
	mlx_clear_window(var->mlx, var->win);
	if (var->opt)
		put_opt_back(var);
	mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	if (var->opt)
		put_opt(var);
	mlx_destroy_image(var->mlx, var->img->img);
}

void	quit_no_args(void)
{
	ft_putendl("usage: ./fractol <fractal>");
	ft_putendl("Fractal : - Mandelbrot");
	ft_putendl("          - Mandelbar");
	ft_putendl("          - Julia");
	ft_putendl("          - Cross");
	ft_putendl("          - BurningShip");
	ft_putendl("          - Bow");
	exit(1);
}

void	quit(t_var *var)
{
	system(AUDIO_OFF);
	ft_memdel((void **)&var->ftl);
	ft_memdel((void **)&var->img);
	ft_memdel((void **)&var->color);
	if (var->mlx && var->win)
	{
		mlx_clear_window(var->mlx, var->win);
		mlx_destroy_window(var->mlx, var->win);
	}
	if (var)
		ft_memdel((void **)&var);
	exit(1);
}
