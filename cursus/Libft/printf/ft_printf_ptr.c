/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-28 17:26:46 by tkulivar          #+#    #+#             */
/*   Updated: 2025-11-28 17:26:46 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_ptr(void *ptr)
{
	unsigned long long	addr;

	addr = (unsigned long long)ptr;
	if (!ptr)
	{
		ft_putstr_fd("(nil)", STDOUT_FILENO);
		return (5);
	}
	ft_putstr_fd("0x", STDOUT_FILENO);
	return (ft_print_hex(addr, 0) + 2);
}
