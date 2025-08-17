/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 23:00:47 by tkulivar          #+#    #+#             */
/*   Updated: 2025/08/03 05:09:41 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	unsigned long long	addr;

	addr = (unsigned long long)ptr;
	if (!ptr)
	{
		ft_putstr_fd("(nil)", FILE_DESC);
		return (5);
	}
	ft_putstr_fd("0x", FILE_DESC);
	return (ft_print_hex(addr, 0) + 2);
}
