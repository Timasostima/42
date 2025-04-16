/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-15 16:28:43 by tkulivar          #+#    #+#             */
/*   Updated: 2025-04-15 16:28:43 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;

	res = (char *)malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s, ft_strlen(s) + 1);
	return (res);
}
