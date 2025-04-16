/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-16 12:37:58 by tkulivar          #+#    #+#             */
/*   Updated: 2025-04-16 12:37:58 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = 0;
	res = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
