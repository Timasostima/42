/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 04:54:08 by tkulivar          #+#    #+#             */
/*   Updated: 2025/08/03 04:59:18 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (c == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(args, int)));
	if (c == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	if (c == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	if (c == '%')
		return (ft_print_percent());
	return (0);
}

int	ft_printf(const char *to_format, ...)
{
	va_list	args;
	int		printed;
	int		i;

	i = 0;
	printed = 0;
	va_start(args, to_format);
	while (to_format[i])
	{
		if (to_format[i] == '%' && to_format[i + 1])
			printed += ft_handle_format(to_format[++i], args);
		else
		{
			ft_putchar_fd(to_format[i], 1);
			printed++;
		}
		i++;
	}
	va_end(args);
	return (printed);
}
