/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:25:17 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/16 16:03:28 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	res = nb;
	while (power > 1)
	{
		res *= nb;
		power--;
	}
	return (res);
}

// int	main(void)
// {
// 	int res = ft_iterative_power(-4,2);
// 	int res1 = ft_iterative_power(0,0);
// 	int res2 = ft_iterative_power(3,0);
// 	int res3 = ft_iterative_power(0,3);
// 	int res4 = ft_iterative_power(4,2);
// 	return (0);
// }
