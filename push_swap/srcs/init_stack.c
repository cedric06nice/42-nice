/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:26:27 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/21 17:16:11 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** First initialization of stack structure
*/
void	init_stack(t_stack *stack)
{
	stack->list_a = NULL;
	stack->list_b = NULL;
	stack->size_a = 0;
	stack->min_a = 0;
	stack->max_a = 0;
	stack->size_b = 0;
	stack->min_b = 0;
	stack->max_b = 0;
	stack->size = 0;
	stack->min = 1;
	stack->max = 0;
	stack->average = 0;
	stack->index = 1;
	stack->flag = 0;
	stack->commands = NULL;
	stack->error = 0;
}
