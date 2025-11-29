/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-02 16:59:00 by tkulivar          #+#    #+#             */
/*   Updated: 2025-08-02 16:59:00 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_find_length(unsigned int n)
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
	return (i);
}

static char	*ft_transform_utoa(unsigned int n)
{
	int		i;
	int		need_l;
	char	*res;

	need_l = ft_find_length((unsigned int)n);
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
	return (res);
}

char	*ft_utoa(unsigned int n)
{
	char	*res;

	res = ft_transform_utoa(n);
	if (!res)
		return (NULL);
	return (res);
}
