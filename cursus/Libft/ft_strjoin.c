/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-15 08:33:33 by tkulivar          #+#    #+#             */
/*   Updated: 2025-04-15 08:33:33 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char*s1, const char *s2)
{
	int		size_s1;
	int		size_s2;
	char	*res;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	res = ft_calloc(size_s1 + size_s2 + 1, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, size_s1 + 1);
	ft_strlcpy(&res[size_s1], s2, size_s2 + 1);
	return res;
}

// int	main(int)
// {
// 	ft_strjoin("Hello ","World");
// }