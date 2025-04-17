/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-10 21:41:56 by tkulivar          #+#    #+#             */
/*   Updated: 2025-04-10 21:41:56 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpy_inv(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*cast_dest;
	const char	*cast_src;

	i = n;
	cast_dest = (char *)dest;
	cast_src = (const char *)src;
	while (i > 0)
	{
		i--;
		cast_dest[i] = cast_src[i];
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest || !src)
		return (NULL);
	if (src > dest)
		return (ft_memcpy(dest, src, n));
	return (ft_memcpy_inv(dest, src, n));
}
