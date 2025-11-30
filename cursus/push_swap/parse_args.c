/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-30 15:27:02 by tkulivar          #+#    #+#             */
/*   Updated: 2025-11-30 15:27:02 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_arr_size(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

static void	extract_values(char **arr, t_list **stack_a, int index)
{
	int		ar_size;
	t_node	*node;

	ar_size = get_arr_size(arr);
	while (index < ar_size)
	{
		node = malloc(sizeof(t_node));
		node->value = ft_atoi(arr[index]);
		node->rank = 0;
		node->pos = 0;
		ft_lstadd_back(stack_a, ft_lstnew(node));
		index++;
	}
}

int	parse_args(int argc, char **argv, t_list **stack_a)
{
	char	**res;

	res = NULL;
	if (argc == 2)
	{
		res = ft_split(argv[1], ' ');
		if (!res || !validate_args(res, 0))
		{
			ft_free_split(res);
			return (0);
		}
		extract_values(res, stack_a, 0);
		ft_free_split(res);
	}
	else
	{
		if (!validate_args(argv, 1))
			return (0);
		extract_values(argv, stack_a, 1);
	}
	return (1);
}
