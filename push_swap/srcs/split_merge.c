/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_merge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 05:21:02 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/14 05:21:28 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Split list_a to list_b to the middle
*/
void	split_list(t_stack *stack)
{
	while (stack->size_a > stack->size / 2)
	{
		if (stack->list_a->order <= stack->size / 2)
			pb(stack);
		else
			ra(stack);
	}
}

/*
** Merge list_b to list_a
*/
void	merge_list(t_stack *stack)
{
	while (stack->size_b > 0)
		pa(stack);
}
