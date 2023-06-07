/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:35:25 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/07 19:33:14 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Return the best move to do
*/
int	only_keeps(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->list_a;
	while (tmp != NULL)
	{
		if (tmp->keep == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/*
** Push in stack_b the best move to do
*/
void	push_b_in_best_a(t_stack *stack)
{
	int	trgt_ord;
	int	bst_mov;

	trgt_ord = order_to_insert_in_a(stack, find_best_move(stack));
	bst_mov = find_best_move(stack);
	while (stack->list_a->order != trgt_ord || stack->list_b->order != bst_mov)
	{
		if (stack->list_a->order != trgt_ord)
		{
			if (find_shortest_route_by_value(trgt_ord,
					stack->list_a) < stack->size_a / 2)
				ra(stack);
			else
				rra(stack);
		}
		if (stack->list_b->order != bst_mov)
		{
			if (find_shortest_route_by_value(bst_mov,
					stack->list_b) < stack->size_b / 2)
				rb(stack);
			else
				rrb(stack);
		}
	}
	pa(stack);
}

/*
** Sort the lists larger than 6 elements
*/
void	sort_large(t_stack *stack)
{
	if (find_best_suite_by_index(stack)
		>= find_best_suite_by_greater_than(stack))
		set_best_suite_by_index(stack);
	else
		set_best_suite_by_greater_than(stack);
	while (only_keeps(stack) == 0)
	{
		if (stack->list_a->keep == 1)
			ra(stack);
		else
			pb(stack);
	}
	while (stack->size_b > 0)
		push_b_in_best_a(stack);
	while (stack->list_a->order != stack->min_a)
	{
		if (find_shortest_route_by_value(stack->min_a,
				stack->list_a) < stack->size_a / 2)
			ra(stack);
		else
			rra(stack);
	}
}
