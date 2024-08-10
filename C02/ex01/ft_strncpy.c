/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 07:50:35 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/21 14:11:14 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (dest[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

// #include <string.h>
// int	main(void)
// {
// 	char src1[] = "thing";
// 	char src2[] = "thing";
// 	char dest1[] = "today";
// 	char dest2[] = "today";
// 	strncpy(dest1, src1, 5);
// 	ft_strncpy(dest2, src2, 5);
// 	return (0);
// }
