/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_shortest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:58:25 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/17 00:16:28 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Find the shortest route to insert the element in the stack
** Returns the index or -1 if the element is not found
*/
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
	return (-1);
}

/*
** Find the shortest route to insert the element in the stack
** Returns the index or -1 if the element is not found
*/
int	find_shortest_route_by_group(int group, t_node *node)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = node;
	while (tmp)
	{
		if (tmp->group == group)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

void	b_shortest_route_value(t_stack *stack, int value)
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

void	b_shortest_route_group(t_stack *stack, int group)
{
	if (find_element_b_by_group(stack, group) < stack->size_b / 2)
	{
		while (stack->list_b->group != group)
			rb(stack);
	}
	else
	{
		while (stack->list_b->group != group)
			rrb(stack);
	}
}

void	push_b_shortest(t_stack *stack)
{
	if (stack->size_b < 2)
		pb(stack);
	else
	{
		if (stack->list_a->group > stack->group_max)
		{
			b_shortest_route_group(stack, stack->group_min);
			pb(stack);
		}
		else if (stack->list_a->group < stack->group_min)
		{
			b_shortest_route_group(stack, stack->group_max);
			pb(stack);
		}
		else
		{
			b_shortest_route_group(stack,
				find_position_to_insert_in_b(stack, stack->list_a->group));
			pb(stack);
		}
	}
}
