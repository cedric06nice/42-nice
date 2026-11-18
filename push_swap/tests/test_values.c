/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 08:07:42 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/22 23:37:10 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	load_in_stack_a(t_stack *stack,
							int x,
							int order,
							int flag,
							int keep)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->x = x;
	new_node->order = order;
	new_node->flag = flag;
	new_node->keep = keep;
	node_insert_end(&stack->list_a, new_node);
	free(new_node);
}

void	load_in_stack_b(t_stack *stack,
							int x,
							int order,
							int flag,
							int keep)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->x = x;
	new_node->order = order;
	new_node->flag = flag;
	new_node->keep = keep;
	node_insert_end(&stack->list_b, new_node);
	free(new_node);
}

t_stack	*load_test_values(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	load_in_stack_a(stack, 30, 30, 0, 0);
	load_in_stack_a(stack, 18, 18, 0, 0);
	load_in_stack_a(stack, 6, 6, 0, 0);
	load_in_stack_a(stack, 17, 17, 0, 0);
	load_in_stack_a(stack, 24, 24, 0, 0);
	load_in_stack_a(stack, 12, 12, 0, 0);
	load_in_stack_a(stack, 10, 10, 0, 0);
	load_in_stack_a(stack, 11, 11, 0, 0);
	load_in_stack_a(stack, 4, 4, 0, 0);
	load_in_stack_a(stack, 5, 5, 0, 0);
	load_in_stack_a(stack, 28, 28, 0, 0);
	load_in_stack_a(stack, 9, 9, 0, 0);
	load_in_stack_a(stack, 27, 27, 0, 0);
	load_in_stack_a(stack, 23, 23, 0, 0);
	load_in_stack_a(stack, 3, 3, 0, 0);
	load_in_stack_a(stack, 2, 2, 0, 0);
	load_in_stack_a(stack, 7, 7, 0, 0);
	load_in_stack_a(stack, 13, 13, 0, 0);
	load_in_stack_a(stack, 1, 1, 0, 0);
	load_in_stack_a(stack, 19, 19, 0, 0);
	load_in_stack_a(stack, 14, 14, 0, 0);
	load_in_stack_a(stack, 26, 26, 0, 0);
	load_in_stack_a(stack, 8, 8, 0, 0);
	load_in_stack_a(stack, 29, 29, 0, 0);
	load_in_stack_a(stack, 22, 22, 0, 0);
	load_in_stack_a(stack, 15, 15, 0, 0);
	load_in_stack_a(stack, 21, 21, 0, 0);
	load_in_stack_a(stack, 20, 20, 0, 0);
	load_in_stack_a(stack, 16, 16, 0, 0);
	load_in_stack_a(stack, 25, 25, 0, 0);
	stack->size = 30;
	stack->min = 0;
	stack->max = 30;
	stack->average = 15;
	stack->index = 1;
	stack->flag = 0;
	stack->error = 0;
	stack->size_a = 30;
	stack->min_a = 1;
	stack->max_a = 30;
	stack->size_b = 0;
	stack->min_b = 0;
	stack->max_b = 0;
	stack->commands = NULL;
	return (stack);
}

t_stack	*execute_push(int nb)
{
	t_stack	*stack;

	stack = load_test_values();
	while (nb > 0)
	{
		pb(stack);
		nb--;
	}
	return (stack);
}
