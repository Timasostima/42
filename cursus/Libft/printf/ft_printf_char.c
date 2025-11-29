/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-28 17:27:05 by tkulivar          #+#    #+#             */
/*   Updated: 2025-11-28 17:27:05 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_char(char c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
	return (1);
}

int	ft_print_str(char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	ft_putstr_fd(s, STDOUT_FILENO);
	return (len);
}

int	ft_print_percent(void)
{
	ft_putchar_fd('%', STDOUT_FILENO);
	return (1);
}
