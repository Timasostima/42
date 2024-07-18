/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:55:43 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/18 17:10:23 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;
	int	temp;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
	{
		temp = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (temp != 0)
			return (temp);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int	main(void)
// {
// 	char	*s1	= "ABC";
// 	char	*s2	= "ABC";
// 	char	*s2_2	= "AB";	
// 	char	*s2_3	= "ABZ";		
// 	int res = ft_strncmp("ABC", "AB", 2);
// 	return (0);	
// }
