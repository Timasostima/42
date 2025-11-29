/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-10 21:20:52 by tkulivar          #+#    #+#             */
/*   Updated: 2025-04-10 21:20:52 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cast_s;

	cast_s = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		cast_s[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
