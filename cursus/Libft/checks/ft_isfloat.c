/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-05 20:50:43 by tkulivar          #+#    #+#             */
/*   Updated: 2025-12-05 20:50:43 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isfloat(const char *str)
{
	int	i;
	int	has_dot;
	int	has_digit;

	if (!str || !*str)
		return (0);
	i = 0;
	has_dot = 0;
	has_digit = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (has_dot++)
				return (0);
		}
		else if (ft_isdigit(str[i]))
			has_digit = 1;
		else
			return (0);
		i++;
	}
	return (has_digit);
}
