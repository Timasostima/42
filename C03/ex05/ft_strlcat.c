/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:51:01 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/21 16:49:46 by tkulivar         ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (size == 0 || size <= dest_len)
		return (src_len + size);
	while (src[i] != '\0' && i < size - dest_len - 1)
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	dest[i + dest_len] = '\0';
	return (dest_len + src_len);
}

// #include <bsd/string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	*src = "Hola";
// 	char	dest[20] = "Tymur";
// 	char	dest1[20] = "Tymur";
// 	int res = ft_strlcat(dest, src, 7);
// 	int res1 = strlcat(dest1, src, 7);
// 	printf("%i\n", res);
// 	printf("%i\n", res1);
// 	printf("%s\n", dest);
// 	printf("%s\n", dest1);
// 	return (0);	
// }
