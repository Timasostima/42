/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-15 17:00:28 by tkulivar          #+#    #+#             */
/*   Updated: 2025-04-15 17:00:28 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	chrs_to_copy;
	size_t	dst_size;		

	dst_size = ft_strlen(dst);
	if (size == 0 || size <= dst_size)
		return (ft_strlen((char *)src) + size);
	chrs_to_copy = size - dst_size - 1;
	i = 0;
	while (i < chrs_to_copy && src[i])
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (dst_size + ft_strlen((char *)src));
}
