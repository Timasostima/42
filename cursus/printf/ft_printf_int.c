/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:36:20 by tkulivar          #+#    #+#             */
/*   Updated: 2025/08/03 05:08:41 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	if (!str)
		return (0);
	len = ft_strlen(str);
	ft_putstr_fd(str, FILE_DESC);
	free(str);
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_utoa(n);
	if (!str)
		return (0);
	len = ft_strlen(str);
	ft_putstr_fd(str, FILE_DESC);
	free(str);
	return (len);
}
