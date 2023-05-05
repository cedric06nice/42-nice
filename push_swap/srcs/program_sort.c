/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:37:57 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/05 08:40:40 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *stack)
{
	int		min;
	int		max;

	min = get_min_a(stack);
	max = get_max_a(stack);
	if (stack->list_a->order == max && stack->list_a->next->order == min)
		ra(stack);
	if (stack->list_a->order == min && stack->list_a->next->order == max)
	{
		sa(stack);
		ra(stack);
	}
	if (stack->list_a->order != min && stack->list_a->next->order == max)
		rra(stack);
	if (stack->list_a->order != min && stack->list_a->next->order == min)
		sa(stack);
	if (stack->list_a->order == max && stack->list_a->next->order != min)
	{
		ra(stack);
		sa(stack);
	}
}

int	find_shortest_route(int min, t_node *node)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = node;
	while (tmp)
	{
		if (tmp->order == min)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

static void	sort_six(t_stack *stack)
{
	while (stack->size_a > 3)
	{
		get_min_values(stack, stack->list_a, stack->size_a);
		while (stack->list_a->order != stack->min)
		{
			if (find_shortest_route(stack->min, stack->list_a) <= 3)
				ra(stack);
			else
				rra(stack);
		}
		pb(stack);
	}
	sort_three(stack);
	merge_list(stack);
}

void	sort(t_stack *stack)
{
	if (nodes_is_sorted(&stack->list_a, '<') == 0)
		exit (0);
	if (stack->size == 2)
	{
		if (stack->list_a->order > stack->list_a->next->order)
			sa(stack);
	}
	else if (stack->size <= 3)
		sort_three(stack);
	else if (stack->size <= 6)
		sort_six(stack);
	else
		sort_large(stack);
}
