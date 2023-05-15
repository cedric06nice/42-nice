/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:30:20 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/15 12:30:22 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Find the element by value in the stack and return the position
** Returns 0 if the element is not found
*/
int	find_element_by_value(t_node *node, int value)
{
	t_node	*tmp;
	int		i;

	tmp = node;
	i = 0;
	while (tmp)
	{
		if (tmp->order == value)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

/*
** Find the element by group in the stack and return the position
** Returns 0 if the element is not found
*/
int	find_element_by_group(t_node *node, int value)
{
	t_node	*tmp;
	int		i;

	tmp = node;
	i = 0;
	while (tmp)
	{
		if (tmp->group == value)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

/*
** Find the first index in stack a and place it to the bottom
** of the stack using the shortest route, increasing the index.
*/
void	find_first_index_a(t_stack *stack)
{
	while (stack->index != 2)
	{
		if (find_shortest_route_by_value(stack->index,
				stack->list_a) < stack->size_a / 2)
		{
			while (stack->list_a->order != stack->index)
				// push_b_shortest(stack);
				ra(stack);
			index_bottom_list_a(stack);
		}
		else
		{
			while (stack->list_a->order != stack->index)
			{
				rra(stack);
				// push_b_shortest(stack);
			}
			index_bottom_list_a(stack);
		}
	}
}

/*
** Find the position to insert in stack and return the index
** Returns -1 if not found
*/
int	find_position_to_insert_in_b(t_stack *stack, int val)
{
	t_node	*tmp;

	if (val < stack->min_b)
		return (stack->min_b);
	if (val > stack->max_b)
		return (stack->max_b);
	tmp = stack->list_b;
	while (tmp)
	{
		if (tmp->next == NULL)
			return (-1);
		if (stack->size_b == 2)
		{
			if (tmp->order < val)
				return (tmp->next->order);
			if (tmp->order > val && val > tmp->next->order)
				return (tmp->next->order);
		}
		else
			return (find_closest_in_b(stack, val));
		tmp = tmp->next;
	}
	return (-1);
}

/*
** Find the closest order available, under value and return it
** Returns -1 if not found
*/
int	find_closest_in_b(t_stack *stack, int val)
{
	t_node	*tmp;
	int		delta;

	delta = val - 1;
	while (delta >= stack->min_b)
	{
		tmp = stack->list_b;
		while (tmp->next != NULL)
		{
			if (find_element_by_value(tmp, delta) != 0)
				return (delta);
			tmp = tmp->next;
		}
		delta--;
	}
	return (-1);
}
