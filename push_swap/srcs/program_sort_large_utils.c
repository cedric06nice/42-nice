/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_sort_large_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:35:25 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/13 12:56:19 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		&& node_get_nth_elmt(all->list_b, all->size_b)->flag == -2)
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

int	find_element_by_group(t_node *node, int value)
{
	t_node	*tmp;
	int		i;

	tmp = node;
	i = 0;
	while (tmp)
	{
		if (tmp->group == value)
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
		if (find_shortest_route_by_value(stack->index, stack->list_a) < stack->size_a / 2)
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

int	find_group_position(int group, t_node *node)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = node;
	while (tmp)
	{
		if (tmp->group == group)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

/*
** Find the closest order available, under value and return it
** Returns -1 if not found
*/
int	find_delta_in_b(t_stack *stack, int val)
{
	t_node	*tmp;
	int		delta;

	delta = val - 1;
	while (delta >= stack->min_b)
	{
		tmp = stack->list_b;
		while (tmp->next != NULL)
		{
			if (find_element_by_value(tmp, delta) != 0)
				return (delta);
			tmp = tmp->next;
		}
		delta--;
	}
	return (-1);
}

/*
** Find the position to insert in stack and return the index
** Returns -1 if not found
*/
int	find_position_to_insert_in_b(t_stack *stack, int val)
{
	t_node	*tmp;
	int		value;

	if (val < stack->min_b)
		return (stack->min_b);
	if (val > stack->max_b)
		return (stack->max_b);
	tmp = stack->list_b;
	while (tmp)
	{
		if (tmp->next == NULL)
			return (-1);
		if (stack->size_b == 2)
		{
			if (tmp->order < val)
				return (tmp->next->order);
			if (tmp->order > val && val > tmp->next->order)
				return (tmp->next->order);
		}
		else
		{
			value = find_delta_in_b(stack, val);
			return (value);
		}
		tmp = tmp->next;
	}
	return (-1);
}

void	push_b_in_order(t_stack *stack)
{
	int	position;

	if (stack->size_b < 2)
		pb(stack);
	else
	{
		if (stack->list_a->order > stack->max_b || stack->list_a->order < stack->min_b)
		{
			if(find_shortest_route_by_value(stack->max_b, stack->list_b) < stack->size_b / 2)
			{
				while (stack->list_b->order != stack->max_b)
					rb(stack);
			}
			else
			{
				while (stack->list_b->order != stack->max_b)
					rrb(stack);
			}
			pb(stack);
		}
		else
		{
			position = find_position_to_insert_in_b(stack, stack->list_a->order);
			if (find_shortest_route_by_value(position, stack->list_b) < stack->size_b / 2)
			{
				while (stack->list_b->order != position)
					rb(stack);
			}
			else
			{
				while (stack->list_b->order != position)
					rrb(stack);
			}
			pb(stack);
		}
	}
}

void	sort_list_a(t_stack *stack)
{
	while (stack->index <= stack->size) // && nodes_is_sorted(&stack->list_a, '<') != 0)
	{
		if (stack->list_a->order == stack->index)
			index_bottom_list_a(stack);
		else if (stack->list_b != NULL && stack->list_b->order == stack->index)
		{
			pa(stack);
			index_bottom_list_a(stack);
		}
		else if (find_element_by_value(stack->list_b, stack->index) != 0)
		{
			if (find_shortest_route_by_value(stack->index, stack->list_b) < stack->size_b / 2)
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
		else if (find_element_by_value(stack->list_b, stack->index) == 0)
		{
			push_b_in_order(stack);
		}
	}
}

void	set_order_arguments(t_stack *stack)
{
	t_node	*node;
	int		prev_val;
	int		before;

	node = stack->list_a;
	node->flag = 1;
	prev_val = 0;
	before = 1;
	while (node != NULL)
	{
		if (before == 1)
		{
			if (node->order == 1)
			{
				before = 0;
				prev_val = node->order;
				node->keep = 1;
			}
		}
		else
		{
			if (node->order == prev_val + 1)
			{
				prev_val = node->order;
				node->keep = 1;
			}
		}
		node = node->next;
	}
	node = stack->list_a;
	while (node != NULL)
	{
		if (node->order == 1)
			break ;
		if (node->order == prev_val + 1)
		{
			prev_val = node->order;
			node->keep = 1;
		}
		node = node->next;
	}
}

void	split_stack_a_to_b(t_stack *stack)
{
	while (stack->list_a)
	{
		if (stack->list_a->keep == 1)
			ra(stack);
		else
			pb(stack);
	}
}

void	sort_large(t_stack *stack)
{
	// set_order_arguments(stack);
	// split_stack_a_to_b(stack);
	find_first_index_a(stack);
	sort_list_a(stack);
}
