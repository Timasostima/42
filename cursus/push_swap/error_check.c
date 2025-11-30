/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-30 14:59:58 by tkulivar          #+#    #+#             */
/*   Updated: 2025-11-30 14:59:58 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(t_list *stack)
{
	t_list	*current;
	t_list	*compare;

	current = stack;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (get_node(current)->value == get_node(compare)->value)
				return (1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_int_overflow(char *str)
{
	long	num;

	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

int	validate_args(char **arr, int start)
{
	int	i;

	i = start;
	while (arr[i])
	{
		if (!is_valid_number(arr[i]) || is_int_overflow(arr[i]))
			return (0);
		i++;
	}
	return (1);
}
