/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_get_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:22:31 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/11 12:54:44 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_min_a(t_stack *stack)
{
	t_node	*tmp;
	int		min;

	if (stack->list_a == NULL)
		return (0);
	tmp = stack->list_a;
	min = tmp->order;
	while (tmp != NULL)
	{
		if (min > tmp->order)
			min = tmp->order;
		tmp = tmp->next;
	}
	stack->min_a = min;
	return (min);
}

int	get_min_b(t_stack *stack)
{
	t_node	*tmp;
	int		min;

	if (stack->list_b == NULL)
		return (0);
	tmp = stack->list_b;
	min = tmp->order;
	while (tmp != NULL)
	{
		if (min > tmp->order)
			min = tmp->order;
		tmp = tmp->next;
	}
	stack->min_b = min;
	return (min);
}

void	get_min_values(t_stack *stack, t_node *node, int size)
{
	t_node	*tmp;
	int		min;
	int		i;

	tmp = node;
	min = tmp->order;
	i = -1;
	while (++i != size)
	{
		if (min > tmp->order)
			min = tmp->order;
		tmp = tmp->next;
	}
	stack->min = min;
}
