/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-12 11:27:33 by tkulivar          #+#    #+#             */
/*   Updated: 2025-04-12 11:27:33 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	size_t	i;
	char	*substr;

	if (!s)
		return NULL;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return ft_strdup("");
	sub_len = s_len - start;
	if (sub_len > len)
		sub_len = len;
	substr = malloc(sub_len + 1);
	if (!substr)
		return NULL;
	i = 0;
	while (i < sub_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return substr;
}

// int main(void)
// {
// 	ft_substr("hola", 0, 11-6);

// }