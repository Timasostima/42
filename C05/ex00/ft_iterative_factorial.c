/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:08:27 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/16 16:03:46 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;
	int	i;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	i = 1;
	res = 1;
	while (i <= nb)
	{
		res *= i;
		i++;
	}
	return (res);
}

// int	main(void)
// {
// 	int res = ft_iterative_factorial(-2);
// 	int res1 = ft_iterative_factorial(0);
// 	int res2 = ft_iterative_factorial(1);
// 	int res3 = ft_iterative_factorial(2);
// 	int res4 = ft_iterative_factorial(5);
// 	return (0);
// }
