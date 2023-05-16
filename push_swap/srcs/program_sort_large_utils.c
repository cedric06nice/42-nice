/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_sort_large_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:35:25 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/17 00:26:16 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Move the first element of list_a to the bottom of list_a
** and increment index
*/
void	index_bottom_list_a(t_stack *stack)
{
	ra(stack);
	stack->index++;
}

/*
** While the index is not equal to the total number of elements
** If the element on top of list a is the next index:
**    swap a and increment index
** If the element on top of list b is the next index:
**    push to a, before swaping a and incrementing index
** If the index is found in stack b:
**    swap b the shortest route and push a in place
** If the index is not found in stack b:
**    swap b the shortest route and push to bottom of a
*/
void	sort_list_a(t_stack *stack)
{
	while (stack->index <= stack->size)
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
			b_shortest_route_value(stack, stack->index);
			pa(stack);
			index_bottom_list_a(stack);
		}
		else if (find_element_by_value(stack->list_b, stack->index) == 0)
			push_b_shortest(stack);
	}
}
