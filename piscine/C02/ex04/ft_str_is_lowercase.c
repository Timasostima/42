/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 07:51:31 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/20 17:11:51 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_lower(char c)
{
	if (c < 'a' || c > 'z')
		return (0);
	return (1);
}

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (check_lower(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

// int main(void)
// {
// 	int str = ft_str_is_lowercase("asdafs");
// 	char res = str + '0';
// 	write(1, &res, 1);
// 	str = ft_str_is_lowercase("asdASFASfasfas");
// 	res = str + '0';
// 	write(1, &res, 1);
// 	str = ft_str_is_lowercase("ASFFSFSAFSF");
// 	res = str + '0';
// 	write(1, &res, 1);
// 	str = ft_str_is_lowercase("");
// 	res = str + '0';
// 	write(1, &res, 1);
// }
