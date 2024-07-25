/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:55:43 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/23 13:42:17 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	pos;

	pos = 0;
	while ((s1[pos] != '\0' || s2[pos] != '\0') && pos < n)
	{
		if (s1[pos] != s2[pos])
			return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
		pos++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	*s1	= "ABC";
// 	char	*s2	= "ABC";
// 	char	*s2_2	= "AB";	
// 	char	*s2_3	= "ABZ";		
// 	int res = ft_strncmp("ABC", "AB", 3);
// 	return (0);	
// }
