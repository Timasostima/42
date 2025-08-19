/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-15 21:22:50 by tkulivar          #+#    #+#             */
/*   Updated: 2025-08-15 21:22:50 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i + 1 < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (ft_strlen((char *)src));
}

char	*ft_strdup_end(const char *s, int index)
{
	char	*res;
	int		size;

	if (index != 0)
		size = ft_strlen(s) + 1 - (ft_strlen(s) - index);
	else
		size = ft_strlen(s) + 1;
	res = ft_calloc(size, 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s, size);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*res;
	char	*str;
	size_t	i;
	size_t	size;
	
	size = elementSize * elementCount;
	res = malloc(size);
	if (!res)
		return (NULL);
	str = (char *)res;
	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	return (res);
}

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}