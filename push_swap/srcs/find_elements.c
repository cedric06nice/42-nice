/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:30:20 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/17 00:30:45 by cpugnair         ###   ########.fr       */
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
** Returns -1 if the element is not found
*/
int	find_element_b_by_group(t_stack *stack, int group)
{
	t_node	*tmp;
	int		i;
	int		j;

	tmp = stack->list_b;
	i = 0;
	while (tmp)
	{
		if (tmp->group == group)
		{
			j = i;
			while (tmp->next && tmp->group == group)
			{
				tmp = tmp->next;
				j++;
			}
			if (i <= stack->size_b - j)
				return (i);
			else
				return (j);
		}
		tmp = tmp->next;
		i++;
	}
	return (-1);
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
				push_b_shortest(stack);
				// ra(stack);
			index_bottom_list_a(stack);
		}
		else
		{
			while (stack->list_a->order != stack->index)
				// rra(stack);
				push_b_shortest(stack);
			index_bottom_list_a(stack);
		}
	}
}

/*
** Find the position to insert in stack and return the index
** Returns -1 if not found
*/
int	find_position_to_insert_in_b(t_stack *stack, int group)
{
	t_node	*tmp;

	if (group < stack->group_min)
		return (stack->group_min);
	if (group > stack->group_max)
		return (stack->group_max);
	tmp = stack->list_b;
	while (tmp)
	{
		if (tmp->next == NULL)
			return (-1);
		if (stack->size_b == 2)
		{
			if (tmp->group <= group)
				return (tmp->group);
			if (tmp->group > group && group >= tmp->next->group)
				return (tmp->next->group);
		}
		else
			return (find_closest_group_in_b(stack, group));
		tmp = tmp->next;
	}
	return (-1);
}

/*
** Find the closest upper group available and return it
** Returns -1 if not found
*/
int	find_closest_group_in_b(t_stack *stack, int group)
{
	t_node	*tmp;
	int		delta;

	delta = group;
	while (delta <= stack->group_max)
	{
		tmp = stack->list_b;
		while (tmp)
		{
			if (tmp->group == delta)
				return (delta);
			tmp = tmp->next;
		}
		delta++;
	}
	return (-1);
}
