/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:18:09 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/16 15:55:02 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

// int	main(void)
// {
// 	int res = ft_recursive_factorial(-2);
// 	int res1 = ft_recursive_factorial(0);
// 	int res2 = ft_recursive_factorial(1);
// 	int res3 = ft_recursive_factorial(2);
// 	int res4 = ft_recursive_factorial(5);
// 	return (0);
// }
