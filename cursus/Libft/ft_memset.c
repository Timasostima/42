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

void	*ft_memset(void *s, int c, long unsigned int n)
{
	long unsigned int	i;

	i = 0;
	while (i < n)
	{
		*((char *)s + i) = (unsigned char)c;
		i++;
	}
	return (s);
}
