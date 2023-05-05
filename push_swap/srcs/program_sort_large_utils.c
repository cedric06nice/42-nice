/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_sort_large_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:35:25 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/05 09:14:35 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	finish_sort(t_stack *all)
{
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
	finish_sort(all);
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
