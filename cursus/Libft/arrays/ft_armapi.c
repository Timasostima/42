/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_armapi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-08 13:26:08 by tkulivar          #+#    #+#             */
/*   Updated: 2026-02-08 13:26:08 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_arrmapi(void **arr, void (*f)(void *))
{
	unsigned int	i;
	char			*res;

	if (!arr || !f)
		return (NULL);
	res = (char *)ft_calloc(ft_arsize(arr) + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		f(arr[i]);
		i++;
	}
	return (res);
}
