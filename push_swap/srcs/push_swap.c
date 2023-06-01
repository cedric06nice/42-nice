/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:37:06 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/01 21:13:53 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (-1);
	stack = init(argc, argv);
	if (stack == NULL || stack->error == 1)
	{
		ft_putstr_fd("Error\n", 2);
		free(stack);
		return (-1);
	}
	sort(stack);
	// reduce_commands(stack);
	print_commands(*stack);
	node_delete(&stack->list_b);
	node_delete(&stack->list_a);
	empty_commands(&stack->commands);
	free(stack);
	// system("leaks push_swap");
	return (0);
}
