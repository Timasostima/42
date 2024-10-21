/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 07:51:13 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/20 17:00:43 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_number(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (check_number(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

// int main(void)
// {
// 	int str = ft_str_is_numeric("hola");
// 	char res = str + '0';
// 	write(1, &res, 1);
// 	str = ft_str_is_numeric("ho12la");
// 	res = str + '0';
// 	write(1, &res, 1);
// 	str = ft_str_is_numeric("1234");
// 	res = str + '0';
// 	write(1, &res, 1);
// 	str = ft_str_is_numeric("");
// 	res = str + '0';
// 	write(1, &res, 1);
// 	return (0);
// }
