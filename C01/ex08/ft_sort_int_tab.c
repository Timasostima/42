/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:42:39 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/08 19:55:21 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	change_i;
	int	temp;

	i = 0;
	while (i < size)
	{
		change_i = 0;
		while (change_i < size - 1)
		{
			if (*(tab + change_i) > *(tab + change_i + 1))
			{
				temp = *(tab + change_i);
				*(tab + change_i) = *(tab + change_i + 1);
				*(tab + change_i + 1) = temp;
			}
			change_i++;
		}
		i++;
	}
}
