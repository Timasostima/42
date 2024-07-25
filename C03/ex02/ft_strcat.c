/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:00:25 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/21 16:09:28 by tkulivar         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	des_len;

	des_len = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[des_len + i] = src[i];
		i++;
	}
	dest[des_len + i] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	char	*src = "Hola";
// 	char	dest[20] = "Tymur";
// 	char *res = ft_strcat(src, dest);
// 	return (0);	
// }
