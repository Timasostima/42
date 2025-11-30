/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-16 11:49:08 by tkulivar          #+#    #+#             */
/*   Updated: 2025-04-16 11:49:08 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_count_segments(char *s, char c)
{
	int	i;
	int	segments;

	i = 0;
	segments = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			segments += 1;
		i++;
	}
	return (segments);
}

static char	*ft_get_substr(char const *s, char c, int start)
{
	int		end;
	char	*substr;

	end = start;
	while (s[end] && s[end] != c)
		end++;
	substr = ft_substr((char const *)s,
			(unsigned int)start, (size_t)(end - start));
	return (substr);
}

static char	*ft_next_substr(char const *s, char c, int seg_i)
{
	int		i;
	int		cur_seg;
	int		first;

	i = 0;
	cur_seg = 0;
	first = 1;
	while (s[i])
	{
		if (seg_i == 0 && s[i] != c)
			return (ft_get_substr(s, c, i));
		else if (first != 0 && s[i] != c && (i == 0 || s[i - 1] == c))
			first = 0;
		else if (s[i] != c && s[i - 1] == c)
		{
			cur_seg += 1;
			if (cur_seg == seg_i)
				return (ft_get_substr(s, c, i));
		}
		i++;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*segment;
	int		segments;
	int		i;

	segments = ft_count_segments((char *)s, c);
	res = ft_calloc(segments + 1, sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (i < segments)
	{
		segment = ft_next_substr(s, c, i);
		if (segment == NULL)
		{
			ft_free_split(res);
			return (NULL);
		}
		res[i] = segment;
		i++;
	}
	return (res);
}
