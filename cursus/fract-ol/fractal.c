/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-06 11:54:25 by tkulivar          #+#    #+#             */
/*   Updated: 2025-12-06 11:54:25 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	check_explodes(t_complex c, t_complex z, int power)
{
	int	iterations;

	iterations = 0;
	while (iterations < MAX_ITERATIONS)
	{
		if (get_magnitude_squared(z) > 4.0)
			return (iterations);
		z = complex_num_power(z, power);
		z = complex_num_sum(z, c);
		iterations++;
	}
	return (0);
}

t_complex	map_pixel_to_complex(int x, int y, double zoom)
{
	t_complex	pixel;

	pixel.real = (x / (double) WIDTH) * zoom - zoom / 2.0 + X_OFFSET;
	pixel.imag = (y / (double) HEIGHT) * zoom - zoom / 2.0 + Y_OFFSET;
	return (pixel);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_color_from_iterations(int iterations)
{
	int	color_intensity;

	if (iterations == 0)
		return (get_rgba(0, 0, 0, 255));
	color_intensity = (iterations * 255) / MAX_ITERATIONS;
	return (get_rgba(255 - color_intensity, color_intensity, color_intensity, 255));
}
