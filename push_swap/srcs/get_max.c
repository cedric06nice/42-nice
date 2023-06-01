/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:22:31 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/21 17:14:09 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max_a(t_stack *stack)
{
	t_node	*tmp;
	int		max;

	if (stack->list_a == NULL)
		return (0);
	tmp = stack->list_a;
	max = tmp->order;
	while (tmp != NULL)
	{
		if (max < tmp->order)
			max = tmp->order;
		tmp = tmp->next;
	}
	stack->max_a = max;
	return (max);
}

int	get_max_b(t_stack *stack)
{
	t_node	*tmp;
	int		max;

	if (stack->list_b == NULL)
		return (0);
	tmp = stack->list_b;
	max = tmp->order;
	while (tmp != NULL)
	{
		if (max < tmp->order)
			max = tmp->order;
		tmp = tmp->next;
	}
	stack->max_b = max;
	return (max);
}

void	get_max_values(t_stack *stack, t_node *node, int size)
{
	t_node	*tmp;
	int		max;
	int		i;

	tmp = node;
	max = tmp->order;
	i = -1;
	while (++i != size)
	{
		if (max < tmp->order)
			max = tmp->order;
		tmp = tmp->next;
	}
	stack->max = max;
}
