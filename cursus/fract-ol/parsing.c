/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-06 12:36:07 by tkulivar          #+#    #+#             */
/*   Updated: 2025-12-06 12:36:07 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	setup_julia(int argc, char **argv, t_fractal *fractal)
{
	fractal->fractal_type = 1;
	if (argc >= 3)
	{
		if (!is_valid_power(argv[2]))
			return (PARSE_FAILURE);
		fractal->power = atoi(argv[2]);
	}
	if (argc >= 4)
	{
		if (!ft_isfloat(argv[3]))
			return (PARSE_FAILURE);
		fractal->c_param.real = ft_atof(argv[3]);
		if (!is_valid_complex_value(fractal->c_param.real))
			return (PARSE_FAILURE);
	}
	if (argc >= 5)
	{
		if (!ft_isfloat(argv[4]))
			return (PARSE_FAILURE);
		fractal->c_param.imag = ft_atof(argv[4]);
		if (!is_valid_complex_value(fractal->c_param.imag))
			return (PARSE_FAILURE);
	}
	return (PARSE_SUCCESS);
}

int	setup_mandelbrot(int argc, char **argv, t_fractal *fractal)
{
	fractal->fractal_type = 0;
	if (argc >= 3)
	{
		if (!is_valid_power(argv[2]))
			return (PARSE_FAILURE);
		fractal->power = atoi(argv[2]);
	}
	return (PARSE_SUCCESS);
}

int	parse_arguments(int argc, char **argv, t_fractal *fractal)
{
	if (argc < 2)
		return (PARSE_FAILURE);
	fractal->needs_redraw = 0;
	fractal->power = 2;
	fractal->c_param.real = -0.4;
	fractal->c_param.imag = 0.6;
	fractal->zoom = 2.0;
	if (ft_strcmp(argv[1], "julia") == 0)
		return (setup_julia(argc, argv, fractal));
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		return (setup_mandelbrot(argc, argv, fractal));
	return (PARSE_FAILURE);
}
