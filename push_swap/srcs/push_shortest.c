/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_shortest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:58:25 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/15 12:30:44 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_shortest_route_by_value(int value, t_node *node)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = node;
	while (tmp)
	{
		if (tmp->order == value)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void	b_shortest_route(t_stack *stack, int value)
{
	if (stack->list_b->order != stack->min_b)
	{
		if (find_shortest_route_by_value(value,
				stack->list_b) < stack->size_b / 2)
		{
			while (stack->list_b->order != value)
				rb(stack);
		}
		else
		{
			while (stack->list_b->order != value)
				rrb(stack);
		}
	}
}

void	push_b_shortest(t_stack *stack)
{
	if (stack->size_b < 2)
	{
		// ft_printf("stack b size = %d\n", stack->size_b);
		pb(stack);
	}
	else
	{
		if (stack->list_a->order > stack->max_b
			|| stack->list_a->order < stack->min_b)
		{
			b_shortest_route(stack, stack->max_b);
			pb(stack);
		}
		else
		{
			b_shortest_route(stack,
				find_position_to_insert_in_b(stack, stack->list_a->order));
			pb(stack);
		}
	}
}
