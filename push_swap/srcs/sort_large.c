/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:35:25 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/01 21:07:52 by cpugnair         ###   ########.fr       */
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
	int	best_to_move;
	int	lista;

	best_to_move = find_best_move(stack);
	lista = order_to_insert_in_a(stack, best_to_move);
	while (stack->list_a->order != lista)
	{
		if (stack->list_a->order != lista)
		{
			if (find_shortest_route_by_value(lista,
					stack->list_a) < stack->size_a / 2)
			{
				// ft_printf("RA ");
				ra(stack);
			}
			else
			{
				// ft_printf("RRA ");
				rra(stack);
			}
		}
	}
	while (stack->list_b->order != best_to_move)
	{
		if (stack->list_b->order != best_to_move)
		{
			if (find_shortest_route_by_value(best_to_move,
					stack->list_b) < stack->size_b / 2)
			{
				// ft_printf("RB ");
				rb(stack);
			}
			else
			{
				// ft_printf("RRB ");
				rrb(stack);
			}
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
