/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-11 18:57:28 by tkulivar          #+#    #+#             */
/*   Updated: 2025-04-11 18:57:28 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*cast_s;

	i = 0;
	cast_s = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (i + 1 < n)
	{
		if (cast_s[i] == (unsigned char) c)
			return ((void *)(s + i));
		i++;
	}
	if (cast_s[i] == (unsigned char) c)
		return ((void *)(s + i));
	return (NULL);
}
