/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-06 12:04:19 by tkulivar          #+#    #+#             */
/*   Updated: 2025-12-06 12:04:19 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	draw_julia(t_fractal *fractal)
{
	t_complex	z;
	int			y;
	int			x;
	int			color;
	int			iterations;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z = map_pixel_to_complex(x, y, fractal->zoom);
			iterations = check_explodes(fractal->c_param, z, fractal->power);
			color = get_color_from_iterations(iterations);
			mlx_put_pixel(fractal->image, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_mandelbrot(t_fractal *fractal)
{
	t_complex	z;
	int			y;
	int			x;
	int			color;
	int			iterations;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			fractal->c_param = map_pixel_to_complex(x, y, fractal->zoom);
			z.real = 0.0;
			z.imag = 0.0;
			iterations = check_explodes(fractal->c_param, z, fractal->power);
			color = get_color_from_iterations(iterations);
			mlx_put_pixel(fractal->image, x, y, color);
			x++;
		}
		y++;
	}
}

int	setup_fractal(t_fractal *fractal)
{
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "Fract-ol", false);
	if (!fractal->mlx)
		return (EXIT_FAILURE);
	fractal->image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->image)
	{
		mlx_terminate(fractal->mlx);
		return (EXIT_FAILURE);
	}
	if (fractal->fractal_type == 1)
		draw_julia(fractal);
	else
		draw_mandelbrot(fractal);
	if (mlx_image_to_window(fractal->mlx, fractal->image, 0, 0) == -1)
	{
		mlx_delete_image(fractal->mlx, fractal->image);
		mlx_terminate(fractal->mlx);
		return (EXIT_FAILURE);
	}
	mlx_scroll_hook(fractal->mlx, &scroll_hook, fractal);
	mlx_key_hook(fractal->mlx, &key_hook, fractal);
	mlx_loop_hook(fractal->mlx, &loop_hook, fractal);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (parse_arguments(argc, argv, &fractal))
	{
		print_usage();
		return (EXIT_FAILURE);
	}
	if (setup_fractal(&fractal) == EXIT_FAILURE)
	{
		print_usage();
		return (EXIT_FAILURE);
	}
	mlx_loop(fractal.mlx);
	mlx_delete_image(fractal.mlx, fractal.image);
	mlx_terminate(fractal.mlx);
	return (EXIT_SUCCESS);
}
