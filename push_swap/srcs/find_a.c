/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 07:28:25 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/01 22:15:10 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Return the order in which to insert stack_b in stack_a
*/
int	order_to_insert_in_a(t_stack *stack, int order)
{
	t_node	*tmp;

	tmp = stack->list_a;
	if (order > stack->max_a || order < stack->min_a)
		return (stack->min_a);
	if (stack->list_a->order > order
		&& order > node_get_nth_elmt(stack->list_a, stack->size_a)->order)
		return (stack->list_a->order);
	while (tmp)
	{
		if (tmp->order < order && order < tmp->next->order)
			return (tmp->next->order);
		tmp = tmp->next;
	}
	free(tmp);
	return (-1);
}

/*
** Find where to insert stack_b in stack_a by order value
** Returns the index
*/
int	find_where_to_insert_in_a(t_stack *stack, int order)
{
	t_node	*tmp;

	tmp = stack->list_a;
	if (order > stack->max_a || order < stack->min_a)
		return (node_get_index_for_order(stack->list_a, stack->min_a));
	if (stack->list_a->order > order
		&& order > node_get_nth_elmt(stack->list_a, stack->size_a)->order)
		return (node_get_index_for_order(stack->list_a, stack->list_a->order));
	while (tmp)
	{
		if (tmp->order < order && order < tmp->next->order)
			return (node_get_index_for_order(stack->list_a, tmp->next->order));
		tmp = tmp->next;
	}
	free(tmp);
	return (-1);
}

static int	find_move_a(t_stack *stack, int order)
{
	if (find_where_to_insert_in_a(stack, order) < stack->size_a / 2)
		return (find_where_to_insert_in_a(stack, order));
	else
		return (stack->size_a - find_where_to_insert_in_a(stack, order));
}

static int	find_move_b(t_stack *stack, int order)
{
	if (find_shortest_route_by_value(order, stack->list_b) < stack->size_b / 2)
		return (find_shortest_route_by_value(order, stack->list_b));
	else
		return (stack->size_b - find_shortest_route_by_value(order,
				stack->list_b));
}

/*
** For each element in stack_b, find the shortest route to insert it in stack_a
** Returns the order value of the shortest route
*/
int	find_best_move(t_stack *stack)
{
	t_node	*tmp;
	int		best;
	int		moves;
	int		order_b;

	tmp = stack->list_b;
	best = stack->max;
	moves = stack->max;
	while (tmp)
	{
		moves = find_move_a(stack, tmp->order) + find_move_b(stack, tmp->order);
		if (moves <= best)
		{
			best = moves;
			order_b = tmp->order;
		}
		if (best == 0)
			return (order_b);
		tmp = tmp->next;
	}
	free(tmp);
	return (order_b);
}
