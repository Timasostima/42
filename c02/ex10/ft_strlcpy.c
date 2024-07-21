/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:42:33 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/20 17:30:10 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				s2;

	i = 0;
	s2 = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (s2);
}

// #include <bsd/string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char src1[] = "hello";
// 	char dest1[] = "fork";
// 	char src2[] = "hello";
// 	char dest2[] = "fork";
// 	unsigned int a = ft_strlcpy(dest1, src1, 3);
// 	unsigned int b = strlcpy(dest2, src2, 3);
// 	printf("%d\n", a);
// 	printf("%s\n", dest1);
// 	printf("%d\n", b);
// 	printf("%s\n", dest2);
// 	return (0);
// }
