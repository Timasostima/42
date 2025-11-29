/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-11 22:32:02 by tkulivar          #+#    #+#             */
/*   Updated: 2025-04-11 22:32:02 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_starts_with(const char *big, const char *lit, size_t start_index)
{
	size_t	i;
	size_t	needed_length;

	i = 0;
	needed_length = ft_strlen((char *)lit);
	while (lit[i] == big[start_index + i])
	{
		i++;
		if (i == needed_length)
			return (1);
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	needed_length;

	if (!*little)
		return ((char *)big);
	if (len < 1)
		return (NULL);
	i = 0;
	needed_length = ft_strlen((char *)little);
	while (big[i] && i + needed_length <= len)
	{
		if (ft_starts_with(big, little, i) == 1)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
