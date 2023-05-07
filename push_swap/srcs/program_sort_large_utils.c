/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_sort_large_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:35:25 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/07 20:00:14 by cpugnair         ###   ########.fr       */
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

// void	sort_large(t_stack *stack)
// {
// 	int	max_flag;

// 	set_average_values(stack);
// 	start_sort(stack, stack->size_a);
// 	while (stack->index <= stack->size)
// 	{
// 		push_a(stack);
// 		max_flag = maxi_flag(stack->list_a, stack->size_a);
// 		while (stack->list_a->flag == max_flag)
// 		{
// 			if (extra_sorting(stack))
// 				continue ;
// 			pb(stack);
// 		}
// 	}
// }

int	find_element(t_node *node, int value)
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

void	index_bottom_list_a(t_stack *stack)
{
	ra(stack);
	stack->index++;
}

void	find_first_index_a(t_stack *stack)
{
	while (stack->index != 2)
	{
		if (find_shortest_route(stack->index, stack->list_a) < stack->size_a / 2)
			{
				while (stack->list_a->order != stack->index)
					ra(stack);
				index_bottom_list_a(stack);
			}
		else
			{
				while (stack->list_a->order != stack->index)
					rra(stack);
				index_bottom_list_a(stack);
			}
	}
}

void	sort_list_a(t_stack *stack)
{
	while (stack->index <= stack->size)// && nodes_is_sorted(&stack->list_a, '<') != 0)
	{
		if (stack->list_a->order == stack->index)
			index_bottom_list_a(stack);
		else if (stack->list_b != NULL && stack->list_b->order == stack->index)
		{
			pa(stack);
			index_bottom_list_a(stack);
		}
		else if (find_element(stack->list_b, stack->index) != 0)
		{
			if (find_shortest_route(stack->index, stack->list_b) < stack->size_b / 2)
				{
					while (stack->list_b->order != stack->index)
						rb(stack);
				}
			else
				{
					while (stack->list_b->order != stack->index)
						rrb(stack);
				}
			pa(stack);
			index_bottom_list_a(stack);
		}
		else if (find_element(stack->list_b, stack->index) == 0)
		{
			pb(stack);
		}
	}
}

void	sort_large(t_stack *stack)
{
	find_first_index_a(stack);
	sort_list_a(stack);
}
