/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 04:53:06 by tkulivar          #+#    #+#             */
/*   Updated: 2025/08/03 05:01:55 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	ft_putchar_fd(c, FILE_DESC);
	return (1);
}

int	ft_print_str(char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	ft_putstr_fd(s, FILE_DESC);
	return (len);
}

int	ft_print_percent(void)
{
	ft_putchar_fd('%', FILE_DESC);
	return (1);
}
