/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:39:56 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/16 15:55:44 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

// int	main(void)
// {
// 	int res = ft_recursive_power(-4,2);
// 	int res1 = ft_recursive_power(0,0);
// 	int res2 = ft_recursive_power(3,0);
// 	int res3 = ft_recursive_power(0,3);
// 	int res4 = ft_recursive_power(4,2);
// 	return (0);
// }
