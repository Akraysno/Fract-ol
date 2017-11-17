/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:23:48 by gauffret          #+#    #+#             */
/*   Updated: 2017/05/10 10:23:50 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	put_options2(t_var *var)
{
	mlx_string_put(var->mlx, var->win, var->width - 245, 165, 0xA9A9A9, \
										"   Default     : [5]");
	mlx_string_put(var->mlx, var->win, var->width - 245, 185, 0x4682B4, \
										"OTHER :");
	mlx_string_put(var->mlx, var->win, var->width - 245, 205, 0xA9A9A9, \
										"   Auto incr i : [HOME]");
	mlx_string_put(var->mlx, var->win, var->width - 245, 225, 0xA9A9A9, \
										"   Block Julia : [TAB]");
	mlx_string_put(var->mlx, var->win, var->width - 245, 245, 0xA9A9A9, \
										"   Son ON/OFF  : [L OPT]");
	mlx_string_put(var->mlx, var->win, 10, var->height - 50, 0xA9A9A9, \
										"   zoom env. : ");
	mlx_string_put(var->mlx, var->win, 160, var->height - 50, 0xF5DEB3, \
										ft_ftoa(var->ftl->zoom, 0, NULL));
	mlx_string_put(var->mlx, var->win, 10, var->height - 30, 0xA9A9A9, \
										"   Iteration (i) : ");
	mlx_string_put(var->mlx, var->win, 200, var->height - 30, 0xF5DEB3, \
										ft_itoa(var->nb_iter));
}

static void	put_options(t_var *var)
{
	mlx_string_put(var->mlx, var->win, var->width - 245, 05, 0x4682B4, \
											"COLOR :");
	mlx_string_put(var->mlx, var->win, var->width - 245, 25, 0xA9A9A9, \
											"   Set 1       : [(]");
	mlx_string_put(var->mlx, var->win, var->width - 245, 45, 0xA9A9A9, \
											"      Color++  : [O]");
	mlx_string_put(var->mlx, var->win, var->width - 245, 65, 0xA9A9A9, \
											"      Color--  : [P]");
	mlx_string_put(var->mlx, var->win, var->width - 245, 85, 0xA9A9A9, \
											"   Set 2       : [)]");
	mlx_string_put(var->mlx, var->win, var->width - 245, 105, 0x4682B4, \
											"WINDOW :");
	mlx_string_put(var->mlx, var->win, var->width - 245, 125, 0xA9A9A9, \
											"   Reduce      : [1]");
	mlx_string_put(var->mlx, var->win, var->width - 245, 145, 0xA9A9A9, \
											"   Extend      : [9]");
	put_options2(var);
}

static void	put_fractal_name(t_var *var)
{
	mlx_string_put(var->mlx, var->win, 10, 05, 0x4682B4, \
													"Fractals : ");
	mlx_string_put(var->mlx, var->win, 10, 25, 0xA9A9A9, \
													"   Mandelbrot   : [!]");
	mlx_string_put(var->mlx, var->win, 10, 45, 0xA9A9A9, \
													"   Mandelbar    : [@]");
	mlx_string_put(var->mlx, var->win, 10, 65, 0xA9A9A9, \
													"   Julia        : [#]");
	mlx_string_put(var->mlx, var->win, 10, 85, 0xA9A9A9, \
													"   Cross        : [$]");
	mlx_string_put(var->mlx, var->win, 10, 105, 0xA9A9A9, \
													"   Burning Ship : [%]");
	mlx_string_put(var->mlx, var->win, 10, 125, 0xA9A9A9, \
													"   Bow          : [^]");
}

static void	put_inter(t_var *var)
{
	mlx_string_put(var->mlx, var->win, var->width - 250, var->height - 110, \
								0x4682B4, "Limits : ");
	mlx_string_put(var->mlx, var->win, var->width - 250, var->height - 90, \
								0xA9A9A9, "   x min : ");
	mlx_string_put(var->mlx, var->win, var->width - 140, var->height - 90, \
								0xF5DEB3, ft_ftoa(var->ftl->x1, 10, NULL));
	mlx_string_put(var->mlx, var->win, var->width - 250, var->height - 70, \
								0xA9A9A9, "   x max : ");
	mlx_string_put(var->mlx, var->win, var->width - 140, var->height - 70, \
								0xF5DEB3, ft_ftoa(var->ftl->x2, 10, NULL));
	mlx_string_put(var->mlx, var->win, var->width - 250, var->height - 50, \
								0xA9A9A9, "   y min : ");
	mlx_string_put(var->mlx, var->win, var->width - 140, var->height - 50, \
								0xF5DEB3, ft_ftoa(var->ftl->y1, 10, NULL));
	mlx_string_put(var->mlx, var->win, var->width - 250, var->height - 30, \
								0xA9A9A9, "   y max : ");
	mlx_string_put(var->mlx, var->win, var->width - 140, var->height - 30, \
								0xF5DEB3, ft_ftoa(var->ftl->y2, 10, NULL));
}

void		put_opt(t_var *var)
{
	put_options(var);
	put_fractal_name(var);
	put_inter(var);
	mlx_string_put(var->mlx, var->win, 10, var->height - ((var->id_fract == 1 \
			|| var->id_fract == 2 || var->id_fract == 5) ? (130) : (70)), \
			0x4682B4, "Settings :");
	if (var->id_fract == 1 || var->id_fract == 2 || var->id_fract == 5)
	{
		mlx_string_put(var->mlx, var->win, 10, var->height - 110, \
										0xA9A9A9, "   Lock : ");
		if (var->move_julia)
			mlx_string_put(var->mlx, var->win, 110, var->height - 110, \
											0xF5DEB3, "No");
		else
			mlx_string_put(var->mlx, var->win, 110, var->height - 110, \
											0xF5DEB3, "Yes");
		mlx_string_put(var->mlx, var->win, 10, var->height - 90, 0xA9A9A9, \
										"   Cursor Re. : ");
		mlx_string_put(var->mlx, var->win, 170, var->height - 90, 0xF5DEB3, \
										ft_ftoa(var->cursorx, 6, NULL));
		mlx_string_put(var->mlx, var->win, 10, var->height - 70, 0xA9A9A9, \
										"   Cursor Im. : ");
		mlx_string_put(var->mlx, var->win, 170, var->height - 70, 0xF5DEB3, \
										ft_ftoa(var->cursory, 6, NULL));
	}
}
