/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-11 07:08:33 by tkulivar          #+#    #+#             */
/*   Updated: 2025-04-11 07:08:33 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	int		i;

	i = 0;
	last = '\0';
	while (s[i])
	{
		if (s[i] == (char) c)
			last = (char *)(s + i);
		i++;
	}
	if (s[i] == (char)c)
		last = (char *)(s + i);
	return (last);
}
