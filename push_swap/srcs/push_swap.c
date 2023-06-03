/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:37:06 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/03 19:17:10 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc >= 2)
	{
		stack = malloc(sizeof(t_stack));
		if (stack == NULL)
			return (-1);
		init(stack, argc, argv);
		if (stack == NULL || stack->list_a == NULL)
		{
			free(stack);
			end_program("Error\n");
		}
		sort(stack);
		reduce_commands(stack);
		print_commands(*stack);
		node_delete(&stack->list_b);
		node_delete(&stack->list_a);
		empty_commands(&stack->commands);
		free(stack);
	}
	return (0);
}
