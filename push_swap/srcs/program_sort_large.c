/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_sort_large.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:35:25 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/15 04:07:48 by cpugnair         ###   ########.fr       */
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
	if (all->size_b >= 2
		&& nodes_get_nth_element(all->list_b, all->size_b - 1)->order == all->index)
	{
		rrb(all);
		rrb(all);
		push_sort(all);
		return (1);
	}
	if (all->size_b > 5)
	{
		if (all->size_b >= 3
			&& nodes_get_nth_element(all->list_b, all->size_b - 2)->order == all->index)
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
		if (nodes_get_nth_element(all->list_b, all->size_b)->order == all->index)
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
	if (all->size_b > 1 && all->list_b && all->list_b->next->order == all->index)
	{
		sb(all);
		push_sort(all);
		return (1);
	}
	if (down_num_b(all))
		return (1);
	return (0);
}

static void	check_a_b(t_stack *all)
{
	if (all->list_b->order >= all->average)
	{
		pa(all);
		all->list_a->flag = all->flag;
	}
	else
	{
		if (all->list_b->order == all->index)
			push_sort(all);
		else
			rb(all);
	}
}

void	push_a(t_stack *all)
{
	int	i;

	while (all->list_b)
	{
		if (extra_sorting(all))
			continue ;
		all->flag++;
		set_average_values(all);
		i = all->size_b;
		while (i--)
			check_a_b(all);
	}
}

int		maxi_flag(t_node *stack, int size)
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

void	start_sort(t_stack *all, int i)
{
	while (all->size_b <= all->average && i--)
	{
		if (all->list_a->order <= all->average)
		{
			pb(all);
			if (all->list_b->order == all->index
				&& all->size_a + all->size_b > 5)
			{
				all->list_b->flag = -2;
				if (all->size_b > 1)
					rb(all);
				all->index++;
			}
		}
		else
			ra(all);
	}
	while (all->size_b >= 2
		&& nodes_get_nth_element(all->list_b, all->size_b)->flag == -2)
		rrr(all);
	while (all->list_b->flag == -2)
	{
		pa(all);
		all->list_a->flag = -1;
		ra(all);
	}
}

void	sort_large(t_stack *stack)
{
	int	max_flag;

	set_average_values(stack);
	start_sort(stack, stack->size_a);
	while (stack->index <= stack->size)
	{
		push_a(stack);
		max_flag = maxi_flag(stack->list_a, stack->size_a);
		while (stack->list_a->flag == max_flag)
		{
			if (extra_sorting(stack))
				continue ;
			pb(stack);
		}
	}
}
