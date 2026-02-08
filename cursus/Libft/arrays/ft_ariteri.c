/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ariteri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-30 11:29:53 by tkulivar          #+#    #+#             */
/*   Updated: 2025-11-30 11:29:53 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_ariteri(void **arr, void (*f)(void *))
{
	size_t	i;

	if (!arr || !f)
		return ;
	i = 0;
	while (arr[i])
	{
		f(arr[i]);
		i++;
	}
}
