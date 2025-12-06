/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-06 11:54:33 by tkulivar          #+#    #+#             */
/*   Updated: 2025-12-06 11:54:33 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;

	(void)xdelta;
	fractal = (t_fractal *) param;
	if (ydelta > 0)
		fractal->zoom *= 0.99;
	else if (ydelta < 0)
		fractal->zoom *= 1.01;
	else
		return ;
	fractal->needs_redraw = 1;
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *) param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(fractal->mlx);
	}
}

void	loop_hook(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *) param;
	if (fractal->needs_redraw)
	{
		if (fractal->fractal_type == 1)
			draw_julia(fractal);
		else
			draw_mandelbrot(fractal);
		fractal->needs_redraw = 0;
	}
}
