/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-15 19:13:21 by tkulivar          #+#    #+#             */
/*   Updated: 2025-04-15 19:13:21 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_find_length(unsigned int n, int flag)
{
	int	i;

	i = 1;
	if (n == 0)
		return (2);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	if (flag == -1)
		i++;
	return (i);
}

static char	*ft_transform_itoa(int n, int flag)
{
	int		i;
	int		need_l;
	char	*res;

	need_l = ft_find_length((unsigned int)n, flag);
	res = (char *)ft_calloc(need_l, sizeof(char));
	if (!res)
		return (NULL);
	i = need_l - 2;
	while (i >= 0)
	{
		res[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	if (flag == -1)
		res[0] = '-';
	return (res);
}

char	*ft_itoa(int n)
{
	int		flag;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	flag = 1;
	if (n < 0)
	{
		flag *= -1;
		n *= -1;
	}
	res = ft_transform_itoa(n, flag);
	if (!res)
		return (NULL);
	return (res);
}
