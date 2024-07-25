/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:06:44 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/24 20:05:52 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	temp;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		temp = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (temp != 0)
			return (temp);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_swap(char **c1, char **c2)
{
	char	*temp;

	temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	change_i;

	i = 1;
	while (i < argc)
	{
		change_i = 1;
		while (change_i < argc - 1)
		{
			if (ft_strcmp(argv[change_i], argv[change_i + 1]) > 0)
				ft_swap(&argv[change_i], &argv[change_i + 1]);
			change_i++;
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
