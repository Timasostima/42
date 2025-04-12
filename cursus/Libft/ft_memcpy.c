/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-10 21:21:05 by tkulivar          #+#    #+#             */
/*   Updated: 2025-04-10 21:21:05 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *in_dest, const void *in_src, long unsigned int n)
{
	long unsigned int	i;
	char				*dest;
	const char			*src;

	if (!in_dest && !in_src)
		return ('\0');
	dest = (char *)in_dest;
	src = (const char *)in_src;
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (in_dest);
}
