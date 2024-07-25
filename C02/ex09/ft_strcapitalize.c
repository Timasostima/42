/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:55:39 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/20 17:22:26 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	to_x_case(char c, int case_type)
{
	if (case_type == 1 && !(c >= 'a' && c <= 'z'))
		c += 32;
	else if (case_type == 2 && !(c >= 'A' && c <= 'Z'))
		c -= 32;
	return (c);
}

int	check_alphabet(char c)
{
	if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
		return (0);
	return (1);
}

int	check_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	new_word;
	int	i;

	i = 0;
	new_word = 1;
	while (str[i] != '\0')
	{
		if (check_alphabet(str[i]) && new_word)
		{
			str[i] = to_x_case(str[i], 2);
			new_word--;
		}
		else if (!check_alphabet(str[i]))
			new_word = 1;
		else
			str[i] = to_x_case(str[i], 1);
		if (check_number(str[i]))
			new_word = 0;
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int main(void)
// {
//     char str1[] 
// 		= "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
//     char* a1 = ft_strcapitalize(str1);
// 	return(0);
// }
