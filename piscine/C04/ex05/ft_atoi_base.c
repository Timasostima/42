/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:58:50 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/24 17:51:53 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_in_base(char num, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == num)
			return (i);
		i++;
	}
	return (i);
}

int	ft_strlen(char *str, char *base, int base_num)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (is_in_base(str[i], base) != base_num))
	{
		i++;
	}
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	sub_i;

	i = 0;
	while (base[i] != '\0')
	{
		sub_i = 0;
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		while (base[sub_i] != '\0')
		{
			if (base[i] == base[sub_i] && i != sub_i)
				return (0);
			sub_i++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

int	ft_atoi_base(char *str, char *base)
{
	int	num;
	int	base_num;
	int	sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	base_num = check_base(base);
	while (*str != '\0' && is_in_base(*str, base) != base_num)
	{
		num += ft_recursive_power(base_num, ft_strlen(str, base, base_num) - 1)
			* is_in_base(*str, base);
		str++;
	}
	return (num * sign);
}

// int	main(void)
// {
// 	int	num = ft_atoi_base(" -F3z1", "0123456789ABCDEF");
// 	int	num1 = ft_atoi_base("iai", "poniguay");
// 	int	num2 = ft_atoi_base("11110011", "01");
// 	int	num3 = ft_atoi_base("babag", "abcdefg");
// 	return (0);
// }
