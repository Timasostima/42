/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-29 20:26:56 by tkulivar          #+#    #+#             */
/*   Updated: 2025-11-29 20:26:56 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reintegration_sort(t_list **a, t_list **b)
{
	int		size;
	t_node	*max_rank;

	while (*b)
	{
		size = ft_lstsize(*b);
		max_rank = find_max_rank(*b);
		if (max_rank->pos <= size / 2)
		{
			while (get_node(*b)->rank != max_rank->rank)
				rb(b);
		}
		else
		{
			while (get_node(*b)->rank != max_rank->rank)
				rrb(b);
		}
		pa(a, b);
	}
}

static void	k_sort(t_list **a, t_list **b)
{
	int	delta;
	int	threshold;

	delta = (ft_lstsize(*a) / 20) + 7;
	threshold = 0;
	while (*a)
	{
		if (get_node(*a)->rank <= threshold + delta)
		{
			pb(a, b);
			if (get_node(*b)->rank <= threshold)
				rb(b);
			threshold++;
		}
		else
			ra(a);
	}
}

static void	sort_stack(t_list **stack_a, t_list **stack_b, int size)
{
	rerank(*stack_a);
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
	{
		k_sort(stack_a, stack_b);
		reintegration_sort(stack_a, stack_b);
	}
}

static void	free_stack(t_list **stack)
{
	t_list	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free((*stack)->content);
		free(*stack);
		*stack = tmp;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv, &stack_a))
	{
		ft_putendl_fd("Error", 2);
		free_stack(&stack_a);
		return (1);
	}
	if (has_duplicates(stack_a))
	{
		ft_putendl_fd("Error", 2);
		free_stack(&stack_a);
		return (1);
	}
	if (!is_sorted(stack_a))
		sort_stack(&stack_a, &stack_b, ft_lstsize(stack_a));
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
