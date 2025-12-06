/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-06 12:33:12 by tkulivar          #+#    #+#             */
/*   Updated: 2025-12-06 12:33:12 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	print_usage(void)
{
	ft_putstr_fd("Usage: ./fract-ol <fractal_type> [options]\n\n", 1);
	ft_putstr_fd("Fractal types:\n", 1);
	ft_putstr_fd("  julia <power> <real> <imag>\n", 1);
	ft_putstr_fd("    power: integer >= 2\n", 1);
	ft_putstr_fd("    real:  real part of c, between -1 and 1 \n", 1);
	ft_putstr_fd("    imag:  imaginary part of c, between -1 and 1 \n\n", 1);
	ft_putstr_fd("  mandelbrot <power>\n", 1);
	ft_putstr_fd("    power: integer >= 2\n\n", 1);
	ft_putstr_fd("Examples:\n", 1);
	ft_putstr_fd("  ./fract-ol julia 2 -0.198 0.792\n", 1);
	ft_putstr_fd("  ./fract-ol julia 2 -0.4 0.6\n", 1);
	ft_putstr_fd("  ./fract-ol julia 7 -0.198 0.792\n", 1);
	ft_putstr_fd("  ./fract-ol mandelbrot 2\n\n", 1);
	ft_putstr_fd("  ./fract-ol mandelbrot 5\n\n", 1);
	ft_putstr_fd("To change offset, zoom, or iterations:\n", 1);
	ft_putstr_fd("  Edit fract_ol.h and modify:\n", 1);
	ft_putstr_fd("    X_OFFSET (e.g., -0.56)\n", 1);
	ft_putstr_fd("    Y_OFFSET (e.g., -0.65)\n", 1);
	ft_putstr_fd("    ZOOM (initial zoom level)\n", 1);
	ft_putstr_fd("    MAX_ITERATIONS (e.g., 40)\n", 1);
}

int	is_valid_power(char *str)
{
	int	num;

	if (!ft_isint(str))
		return (0);
	num = atoi(str);
	return (num >= 2);
}

int	is_valid_complex_value(double value)
{
	return (value >= -1.0 && value <= 1.0);
}
