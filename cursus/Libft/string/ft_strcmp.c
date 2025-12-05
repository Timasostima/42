/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-05 19:19:12 by tkulivar          #+#    #+#             */
/*   Updated: 2025-12-05 19:19:12 by tkulivar         ###   ########.fr       */
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
