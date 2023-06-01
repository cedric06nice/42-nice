/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:11:13 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/31 23:31:20 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	t_stack	*stack;

	stack = load_test_values();
	if (find_best_suite_by_index(stack) >= find_best_suite_by_greater_than(stack))
		set_best_suite_by_index(stack);
	else
		set_best_suite_by_greater_than(stack);
	while (only_keeps(stack) == 0)
	{
		if (stack->list_a->keep == 1)
			ra(stack);
		else
			pb(stack);
	}
	// print_linear(*stack, 1);
	print_linear(*stack, 1);
	// reduce_commands(stack);
	// print_linear(*stack, 1);
	// print_commands(*stack);
	// node_delete(&stack->list_a);
	// node_delete(&stack->list_b);
	// empty_commands(&stack->commands);
	// free(stack);
	return (0);
}
