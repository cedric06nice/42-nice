/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_greater_than.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 07:28:25 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/19 09:01:56 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	second_part(t_node *node, int index, int size, int count)
{
	while (size >= 0)
	{
		if (node->order >= index)
		{
			node->keep = 1;
			index = node->order + 1;
			count++;
		}
		size--;
		node = node->next;
	}
	return (count);
}

/*
** Find the number of elements greater than each other in the stack.
** Return the number of elements in the serie.
*/
static int	serie(t_stack *stack, int index)
{
	t_node	*node;
	int		size;
	int		count;

	node = stack->list_a;
	size = stack->size;
	count = 0;
	while (node->order != index)
		node = node->next;
	while (node)
	{
		if (node->order >= index)
		{
			node->keep = 1;
			index = node->order + 1;
			count++;
		}
		size--;
		node = node->next;
	}
	return (second_part(stack->list_a, index, size, count));
}

/*
** Find the best serie in the stack by greater than
** Return the number of elements in the best serie
*/
int	find_best_suite_by_greater_than(t_stack *stack)
{
	int	best_serie;
	int	i;

	best_serie = 0;
	i = 1;
	while (i <= stack->size)
	{
		if (serie(stack, i) > best_serie)
			best_serie = serie(stack, i);
		i++;
	}
	reset_keep(stack);
	return (best_serie);
}

/*
** Set the values to keep in the stack by greater than
*/
void	set_best_suite_by_greater_than(t_stack *stack)
{
	int	best_serie;
	int	i;

	best_serie = find_best_suite_by_greater_than(stack);
	i = 1;
	reset_keep(stack);
	while (i <= stack->size)
	{
		if (serie(stack, i) == best_serie)
			return ;
		i++;
		reset_keep(stack);
	}
}
