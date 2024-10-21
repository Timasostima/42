/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:00:09 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/10 00:36:54 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	cent;
	char	dec;
	char	uni;

	cent = '0';
	while (cent <= '7')
	{
		dec = cent + 1;
		while (dec <= '8')
		{
			uni = dec + 1;
			while (uni <= '9')
			{
				write(1, &cent, 1);
				write(1, &dec, 1);
				write(1, &uni, 1);
				if (cent != '7')
					write(1, ", ", 2);
				uni++;
			}
			dec++;
		}
		cent++;
	}
}
