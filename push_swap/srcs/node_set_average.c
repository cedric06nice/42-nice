/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_set_average.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:22:31 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/13 11:41:27 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Set min_a, min_b, max_a, max_b et average.
*/
void	set_average_values(t_stack *stack)
{
	get_min_a(stack);
	get_max_a(stack);
	get_min_b(stack);
	get_max_b(stack);
	if (stack->min_a < stack->min_b)
		stack->min = stack->min_a;
	else
		stack->min = stack->min_b;
	if (stack->max_a > stack->max_b)
		stack->max = stack->max_a;
	else
		stack->max = stack->max_b;
	stack->average = (stack->max - stack->min) / 2 + stack->min;
}
