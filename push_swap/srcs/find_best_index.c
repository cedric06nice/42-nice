/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 07:28:25 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/19 08:40:24 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Reset all keep values to 0
*/
void	reset_keep(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->list_a;
	while (tmp)
	{
		tmp->keep = 0;
		tmp = tmp->next;
	}
}

static int	second_part_gt(t_node *node,
							int index,
							int size,
							int count)
{
	while (size-- > 0)
	{
		if (node->order == index)
		{
			node->keep = 1;
			index++;
			count++;
		}
		node = node->next;
	}
	return (count);
}

/*
** Find the number of elements following each other in the stack.
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
		if (node->order == index)
		{
			node->keep = 1;
			index++;
			count++;
		}
		size--;
		node = node->next;
	}
	return (second_part_gt(stack->list_a, index, size, count));
}

/*
** Find the best serie in the stack by index
** Return the number of elements in the best serie
*/
int	find_best_suite_by_index(t_stack *stack)
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
** Set the values to keep in the stack by index
*/
void	set_best_suite_by_index(t_stack *stack)
{
	int	best_serie;
	int	i;

	best_serie = find_best_suite_by_index(stack);
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
