/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:59:24 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/24 15:14:00 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i <= nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

// int	main(void)
// {
// 	int res = ft_is_prime(-2);
// 	int res1 = ft_is_prime(0);
// 	int res2 = ft_is_prime(2);
// 	int res3 = ft_is_prime(4);
// 	int res4 = ft_is_prime(5);
// 	return (0);
// }
