/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-12 17:00:26 by tkulivar          #+#    #+#             */
/*   Updated: 2025-04-12 17:00:26 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		closest_ten;
	char	current_digit;

	closest_ten = 1;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	while (n / closest_ten >= 10)
	{
		closest_ten *= 10;
	}
	while (closest_ten >= 1)
	{
		current_digit = n / closest_ten % 10 + '0';
		closest_ten /= 10;
		ft_putchar_fd(current_digit, fd);
	}
}

// int	main(void)
// {
// 	ft_putnbr_fd(532, 1);
// }