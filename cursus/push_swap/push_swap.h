/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-30 15:27:09 by tkulivar          #+#    #+#             */
/*   Updated: 2025-11-30 15:27:09 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>

typedef struct s_node
{
	int	value;
	int	rank;
	int	pos;
}	t_node;

t_node	*get_node(t_list *stack);
t_node	*find_max_rank(t_list *stack);
void	rerank(t_list *stack);
int		is_sorted(t_list *stack);

int		is_valid_number(char *str);
int		has_duplicates(t_list *stack);
int		is_int_overflow(char *str);
int		validate_args(char **arr, int start);

int		parse_args(int argc, char **argv, t_list **stack_a);

void	sort_two(t_list **a);
void	sort_three(t_list **a);
void	sort_four(t_list **a, t_list **b);
void	sort_five(t_list **a, t_list **b);

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

#endif
