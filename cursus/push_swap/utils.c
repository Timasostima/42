/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-30 15:26:08 by tkulivar          #+#    #+#             */
/*   Updated: 2025-11-30 15:26:08 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_node(t_list *stack)
{
	return ((t_node *)stack->content);
}

t_node	*find_max_rank(t_list *stack)
{
	t_node	*max;
	t_list	*current;
	int		pos;

	max = get_node(stack);
	current = stack;
	pos = 0;
	while (current)
	{
		if (get_node(current)->rank > max->rank)
		{
			get_node(current)->pos = pos;
			max = get_node(current);
		}
		current = current->next;
		pos++;
	}
	return (max);
}

void	rerank(t_list *stack)
{
	t_list	*current;
	t_list	*compare;
	int		rank;
	int		curr_val;

	current = stack;
	while (current)
	{
		rank = 0;
		compare = stack;
		curr_val = get_node(current)->value;
		while (compare)
		{
			if (get_node(compare)->value < curr_val)
				rank++;
			compare = compare->next;
		}
		get_node(current)->rank = rank;
		current = current->next;
	}
}

int	is_sorted(t_list *stack)
{
	t_list	*current;

	if (!stack)
		return (1);
	current = stack;
	while (current->next)
	{
		if (get_node(current)->value > get_node(current->next)->value)
			return (0);
		current = current->next;
	}
	return (1);
}
