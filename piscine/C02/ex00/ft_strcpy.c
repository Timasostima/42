/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 07:50:03 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/20 16:56:16 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <string.h>
// int	main(void)
// {
// 	char src1[] = "thing";
// 	char src2[] = "thing";
// 	char dest1[] = "today";
// 	char dest2[] = "today";
// 	strcpy(dest1, src1);
// 	ft_strcpy(dest2, src2);
// 	return (0);
// }
