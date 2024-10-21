/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:33:30 by vbengea           #+#    #+#             */
/*   Updated: 2024/07/07 16:27:48 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);
void	ft_print_line(int x, char fl, char ml, char ll);

void	rush(int y, int x)
{
	int	i;

	i = 1;
	if (y <= 0 || x <= 0)
		write(1, "ERROR", 5);
	while (i <= y)
	{
		if (i == 1)
		{
			ft_print_line(x, 'o', '-', 'o');
		}
		else if (i == y)
		{
			ft_print_line(x, 'o', '-', 'o');
		}
		else
		{
			ft_print_line(x, '|', ' ', '|');
		}
		i++;
		ft_putchar('\n');
	}
}

void	ft_print_line(int x, char fl, char ml, char ll)
{
	int	i;

	i = 1;
	while (i <= x)
	{
		if (i == 1)
		{
			ft_putchar(fl);
		}
		else if (i == x)
		{
			ft_putchar(ll);
		}
		else
		{
			ft_putchar(ml);
		}
		i++;
	}
}
