/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:07:23 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/21 14:13:32 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_transform(unsigned char nbr)
{
	int				base_num;
	unsigned char	*base;

	base = (unsigned char *)"0123456789abcdef";
	base_num = 16;
	write(1, &base[nbr / base_num], 1);
	write(1, &base[nbr % base_num], 1);
}

int	check_printable(char c)
{
	if (!(c >= 32 && c <= 126))
		return (0);
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (check_printable(str[i]) == 0)
		{
			write(1, "\\", 1);
			ft_putnbr_transform((unsigned char) str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

// int	main(void)
// {
// 	ft_putstr_non_printable("Coucou\201tu vas bien ?");
// }
