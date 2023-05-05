/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_sort_large.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:35:25 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/05 09:15:01 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_sort(t_stack *all)
{
	pa(all);
	all->list_a->flag = -1;
	ra(all);
	all->index++;
}

static int	pre_last(t_stack *all)
{
	if (all->size_b >= 2 && nodes_get_nth_element(all->list_b,
			all->size_b - 1)->order == all->index)
	{
		rrb(all);
		rrb(all);
		push_sort(all);
		return (1);
	}
	if (all->size_b > 5)
	{
		if (all->size_b >= 3 && nodes_get_nth_element(all->list_b,
				all->size_b - 2)->order == all->index)
		{
			rrb(all);
			rrb(all);
			rrb(all);
			push_sort(all);
			return (1);
		}
	}
	return (0);
}

static int	down_num_b(t_stack *all)
{
	if (all->size_b > 3)
	{
		if (nodes_get_nth_element(all->list_b,
				all->size_b)->order == all->index)
		{
			rrb(all);
			push_sort(all);
			return (1);
		}
		if (pre_last(all))
			return (1);
	}
	return (0);
}

int	extra_sorting(t_stack *all)
{
	if (all->list_a->order == all->index)
	{
		all->list_a->flag = -1;
		ra(all);
		all->index++;
		return (1);
	}
	if (all->list_b && all->list_b->order == all->index)
	{
		push_sort(all);
		return (1);
	}
	if (all->size_b > 1 && all->list_b
		&& all->list_b->next->order == all->index)
	{
		sb(all);
		push_sort(all);
		return (1);
	}
	if (down_num_b(all))
		return (1);
	return (0);
}

int	maxi_flag(t_node *stack, int size)
{
	int		max;
	t_node	*tmp;

	max = 0;
	tmp = stack;
	while (tmp && size--)
	{
		if (tmp->flag > max && tmp->flag >= 0)
			max = tmp->flag;
		tmp = tmp->next;
	}
	return (max);
}
