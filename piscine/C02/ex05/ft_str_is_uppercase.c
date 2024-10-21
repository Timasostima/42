/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 07:52:23 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/10 07:52:30 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_upper(char c)
{
	if (c < 'A' || c > 'Z')
		return (0);
	return (1);
}

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (check_upper(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

// int main(void)
// {
// 	int str = ft_str_is_uppercase("asdafs");
// 	char res = str + '0';
// 	write(1, &res, 1);
// 	str = ft_str_is_uppercase("asdASFASfasfas");
// 	res = str + '0';
// 	write(1, &res, 1);
// 	str = ft_str_is_uppercase("ASFFSFSAFSF");
// 	res = str + '0';
// 	write(1, &res, 1);
// 	str = ft_str_is_uppercase("");
// 	res = str + '0';
// 	write(1, &res, 1);
// }
