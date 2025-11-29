/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-28 17:27:00 by tkulivar          #+#    #+#             */
/*   Updated: 2025-11-28 17:27:00 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_get_base_len(unsigned long long n, unsigned int base)
{
	int	len;

	len = 1;
	while (n >= base)
	{
		n /= base;
		len++;
	}
	return (len);
}

static char	*ft_itoa_base(unsigned long long n,
		unsigned int base, unsigned int len, char *digits)
{
	char	*str;

	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	len--;
	while (n > 0)
	{
		str[len] = digits[n % base];
		n /= base;
		len--;
	}
	return (str);
}

int	ft_print_hex(unsigned long long n, int uppercase)
{
	char	*hex_digits;
	char	*result;
	int		len;

	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	if (n == 0)
	{
		ft_putchar_fd('0', STDOUT_FILENO);
		return (1);
	}
	len = ft_get_base_len(n, 16);
	result = ft_itoa_base(n, 16, len, hex_digits);
	if (!result)
		return (0);
	ft_putstr_fd(result, STDOUT_FILENO);
	free(result);
	return (len);
}
