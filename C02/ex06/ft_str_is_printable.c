/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 07:52:41 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/18 13:25:02 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_printable(char c)
{
	if (!(c >= 32 && c <= 126))
		return (0);
	return (1);
}

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (check_printable(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

// int main(void)
// {
// 	int str = ft_str_is_printable("qweretrtyuyi245");
// 	char res = str + '0';
// 	write(1, &res, 1);
// 	str = ft_str_is_printable("ñ");
// 	res = str + '0';
// 	write(1, &res, 1);
// 	str = ft_str_is_printable("");
// 	res = str + '0';
// 	write(1, &res, 1);
// }
