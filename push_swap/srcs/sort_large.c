/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:35:25 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/01 22:04:07 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	push_b_in_best_a(t_stack *stack)
{
	while (stack->list_a->order != order_to_insert_in_a(stack,
			find_best_move(stack))
		|| stack->list_b->order != find_best_move(stack))
	{
		if (stack->list_a->order != order_to_insert_in_a(stack,
				find_best_move(stack)))
		{
			if (find_shortest_route_by_value(order_to_insert_in_a(stack,
						find_best_move(stack)),
					stack->list_a) < stack->size_a / 2)
				ra(stack);
			else
				rra(stack);
		}
		if (stack->list_b->order != find_best_move(stack))
		{
			if (find_shortest_route_by_value(find_best_move(stack),
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
				stack->list_a) < stack->size_b / 2)
			ra(stack);
		else
			rra(stack);
	}
}
