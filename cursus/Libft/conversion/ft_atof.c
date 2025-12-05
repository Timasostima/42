/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-05 19:20:29 by tkulivar          #+#    #+#             */
/*   Updated: 2025-12-05 19:20:29 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static double	power_of_10(int n)
{
	double	result;

	result = 1.0;
	while (n > 0)
	{
		result *= 10.0;
		n--;
	}
	return (result);
}

static size_t	decimal_length(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] >= '0' && str[len] <= '9')
		len++;
	return (len);
}

double	ft_atof(const char *str)
{
	double		result;
	const char	*decimal_part;
	int			sign;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = (double)ft_atoi(str);
	decimal_part = ft_strchr(str, '.');
	if (decimal_part)
	{
		decimal_part++;
		result += (double)ft_atoi(decimal_part)
			/ power_of_10(decimal_length(decimal_part));
	}
	return (result * sign);
}
