/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:07:02 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/15 17:19:22 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	temp;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
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
// 	int res = ft_strcmp("\201", "A");
// 	return (0);	
// }
