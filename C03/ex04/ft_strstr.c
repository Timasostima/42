/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:12:13 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/21 16:38:42 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	sub_i;

	i = 0;
	if (to_find[0] == '\0')
		return (&str[0]);
	while (str[i] != '\0')
	{
		sub_i = 0;
		while (to_find[sub_i] == str[i + sub_i] && str[i + sub_i] != '\0')
		{
			if (to_find[sub_i + 1] == '\0')
				return (&str[i]);
			sub_i++;
		}
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*sub_str;
// 	char	*ss_pos;
// 	str = "Hello World!";
// 	sub_str = "World";
// 	ss_pos = ft_strstr(str, sub_str);
// 	return(0);	
// }
