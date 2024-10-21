/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:27:19 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/16 16:30:24 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(int nb)
{
	int		digits;	
	int		digit;
	char	digit_char;

	digits = 1;
	while (digits < (nb / 10))
	{
		digits *= 10;
	}
	while (digits >= 1)
	{
		digit = (nb / digits) % 10;
		digit_char = digit + '0';
		write(1, &digit_char, 1);
		digits /= 10;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	print_num(nb);
}

// int	main(void)
// {
// 	ft_putnbr(-2147483648);
// 	write(1, "\n", 1);
// 	ft_putnbr(2147483647);
// 	write(1, "\n", 1);
// 	ft_putnbr(34);
// 	write(1, "\n", 1);
// 	ft_putnbr(-124);
// }
