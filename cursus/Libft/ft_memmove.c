/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-10 21:41:56 by tkulivar          #+#    #+#             */
/*   Updated: 2025-04-10 21:41:56 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, long unsigned int n)
{
	char	temp[n];
	long unsigned int i;

	if (!dest && !src)
		return ('\0');
	i = 0;
	while (i < n){
		temp[n] = 0;
		i++;
	}
	ft_memcpy(temp, src, n);
	ft_memcpy(dest, temp, n);
	return (dest);
}