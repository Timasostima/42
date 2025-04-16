/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-15 23:20:21 by tkulivar          #+#    #+#             */
/*   Updated: 2025-04-15 23:20:21 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_segments(char *s, char c)
{
	int	i;
	int	first;
	int	segments;
	
	i = 0;
	first = 1;
	segments = 1;
	while (s[i]==c && s[i])
		i++;
	while (s[i])
	{
		if (first && s[i] != c && (i==0 || s[i - 1] == c))
			first = 0;
		else if (s[i] != c && s[i - 1] == c)
			segments += 1;
		i++;
	}
	return segments;
}

char	*get_substr(const char *s, char c, int start)
{
	int		end;
	char	*substr;

	end = start;
	while (s[end] && s[end] != c)
	{
		end++;
	}

	substr = ft_substr((const char *)s,
		(unsigned int)start, (size_t)(end - start));
	return (substr);
}

char 	*next_substr(const char *s, char c, int seg_i)
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
			return get_substr(s, c, i);
		else if (first && s[i] != c && (i==0 || s[i - 1] == c))
			first = 0;
		else if (s[i] != c && s[i - 1] == c)
		{
			cur_seg += 1;
			if (cur_seg == seg_i)
				return get_substr(s, c, i);
		}
		i++;
	}
	return NULL;

}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*segment;
	int		segments;
	int		i;

	segments = count_segments((char *)s, c);
	res = (char **)malloc(segments * sizeof(char *) + 1);
	i = 0;
	while (i < segments)
	{
		segment = next_substr(s, c, i);
		res[i] = segment;
		i++;
	}
	res[i] = NULL;
	return res;
}

// int	main(void)
// {
// 	// ft_split("Hello World", ' ');
// 	// ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
// 	// ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
// 	// ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
// 	ft_split("Hello!", '^');
// }