/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-06 12:37:11 by tkulivar          #+#    #+#             */
/*   Updated: 2025-12-06 12:37:11 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	get_magnitude_squared(t_complex num)
{
	return (num.real * num.real + num.imag * num.imag);
}

t_complex	complex_num_power(t_complex num, int power)
{
	t_complex	result;
	t_complex	base;
	double		temp_real;
	int			i;

	if (power == 0)
	{
		result.real = 1.0;
		result.imag = 0.0;
		return (result);
	}
	result = num;
	base = num;
	i = 1;
	while (i < power)
	{
		temp_real = result.real * base.real - result.imag * base.imag;
		result.imag = result.real * base.imag + result.imag * base.real;
		result.real = temp_real;
		i++;
	}
	return (result);
}

t_complex	complex_num_sum(t_complex num1, t_complex num2)
{
	t_complex	result;

	result.real = num1.real + num2.real;
	result.imag = num1.imag + num2.imag;
	return (result);
}
