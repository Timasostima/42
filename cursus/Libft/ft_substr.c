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
	size_t		i;
	char	*substr;

	substr = (char *)malloc(sizeof(char const *) * len + 1);
	if (substr == NULL)
		return NULL;
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	return substr;
}

// int main(void)
// {
// 	ft_substr("hola", 0, 18446744073709551615);
// }