/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-30 15:25:55 by tkulivar          #+#    #+#             */
/*   Updated: 2025-11-30 15:25:55 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **a)
{
	if (get_node(*a)->rank > get_node((*a)->next)->rank)
		sa(a);
}

void	sort_three(t_list **a)
{
	int	r1;
	int	r2;

	r1 = get_node(*a)->rank;
	r2 = get_node((*a)->next)->rank;
	if (r1 == 1 && r2 == 0)
		sa(a);
	else if (r1 == 2 && r2 == 1)
	{
		sa(a);
		rra(a);
	}
	else if (r1 == 2 && r2 == 0)
		ra(a);
	else if (r1 == 0 && r2 == 2)
	{
		sa(a);
		ra(a);
	}
	else if (r1 == 1 && r2 == 2)
		rra(a);
}

static void	rotate_max_to_top(t_list **a)
{
	t_node	*max;
	int		size;

	size = ft_lstsize(*a);
	max = find_max_rank(*a);
	if (max->pos <= size / 2)
	{
		while (get_node(*a)->rank != max->rank)
			ra(a);
	}
	else
	{
		while (get_node(*a)->rank != max->rank)
			rra(a);
	}
}

void	sort_four(t_list **a, t_list **b)
{
	rotate_max_to_top(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	ra(a);
}

void	sort_five(t_list **a, t_list **b)
{
	rotate_max_to_top(a);
	pb(a, b);
	rotate_max_to_top(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	ra(a);
	pa(a, b);
	ra(a);
}
