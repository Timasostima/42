/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:08:14 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/24 20:11:19 by tkulivar         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}

// int	main(void)
// {
// 	int res = ft_find_next_prime(-2);
// 	int res1 = ft_find_next_prime(2);
// 	int res2 = ft_find_next_prime(4);
// 	int res3 = ft_find_next_prime(5);
// 	int res4 = ft_find_next_prime(14);
// 	return (0);
// }
