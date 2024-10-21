/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 07:50:58 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/20 16:58:01 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_alphabet(char c)
{
	if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
		return (0);
	return (1);
}

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (check_alphabet(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

// int main(void)
// {
// 	int str = ft_str_is_alpha("hola");
// 	char res = str + '0';
// 	write(1, &res, 1);
// 	str = ft_str_is_alpha("HOLA");
// 	res = str + '0';
// 	write(1, &res, 1);
// 	str = ft_str_is_alpha("Ho1lA");
// 	res = str + '0';
// 	write(1, &res, 1);
// 	str = ft_str_is_alpha("1234");
// 	res = str + '0';
// 	write(1, &res, 1);
// 	str = ft_str_is_alpha("");
// 	res = str + '0';
// 	write(1, &res, 1);
// 	return (0);
// }
