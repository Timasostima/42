/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:22:50 by tkulivar          #+#    #+#             */
/*   Updated: 2025/08/19 21:31:06 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*strjoin_and_update(char **line, char *buffer)
{
	int		size_s1;
	int		size_s2;
	char	*temp;

	if (!*line && !buffer)
		return (NULL);
	if (!*line)
		return (*line = ft_strdup(buffer));
	if (!buffer)
		return (*line);
	size_s1 = ft_strlen(*line);
	size_s2 = ft_strlen(buffer);
	temp = malloc(size_s1 + size_s2 + 1);
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, *line, size_s1 + 1);
	ft_strlcpy(&temp[size_s1], buffer, size_s2 + 1);
	if (*line)
		free(*line);
	return (*line = temp);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!src || !dst)
		return (0);
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

char	*ft_strdup(const char *s)
{
	char	*res;
	int		size;

	if (!s)
		return (NULL);
	size = ft_strlen(s) + 1;
	res = malloc(size);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s, size);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
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

size_t	ft_strlen(const char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}
