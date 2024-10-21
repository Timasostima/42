/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:20:51 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/24 15:21:25 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base(char *base)
{
	int	i;
	int	sub_i;

	i = 0;
	while (base[i] != '\0')
	{
		sub_i = 0;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[sub_i] != '\0')
		{
			if (base[i] == base[sub_i] && i != sub_i)
				return (0);
			sub_i++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

void	ft_putnbr_transform(int nbr, int base_num, char *base)
{
	if (nbr < base_num)
	{
		write(1, &base[nbr % base_num], 1);
		return ;
	}
	ft_putnbr_transform(nbr / base_num, base_num, base);
	write(1, &base[nbr % base_num], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_num;
	int		i;

	i = 0;
	base_num = check_base(base);
	if (base_num == 0)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		if (nbr <= -base_num)
			ft_putnbr_transform(-(nbr / base_num), base_num, base);
		ft_putnbr_transform(-(nbr % base_num), base_num, base);
	}
	else
		ft_putnbr_transform(nbr, base_num, base);
}

// int	main(void)
// {
// 	ft_putnbr_base(243, "0123456789");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-2147483648, "0123456789");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(243, "012345678\65ABCDEF");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-243, "0123456789ABCDEF");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(243, "01");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(243, "poniguay");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-2, "0123456789ABCDEF");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(2, "0123456789ABCDEF");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(2456, "abcdefg");
// 	return (0);
// }
