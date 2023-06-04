/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 07:47:20 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/04 15:42:45 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Initialization of stack structure
** Load arguments into stack->list_a
** Assign index number to each node in stack->list_a
** Set average values for stack->list_a
** Check for duplicates in stack->list_a
*/
void	init(t_stack *stack, int argc, char **argv)
{
	int	*list_num;

	init_stack(stack);
	if (argc == 2)
	{
		if (argv[1][0] == '\0')
			end_program("Error");
		list_num = string_to_number(argv[1], &stack->size);
	}
	if (argc > 2)
		list_num = numbers_to_number(argc, argv, &stack->size);
	if (list_num == NULL)
		end_program("Error");
	load_arguments(stack, list_num);
	free(list_num);
	set_average_values(stack);
	if (node_check_dup(stack->list_a) == 1)
	{
		node_delete(&stack->list_a);
		end_program("Error");
	}
}
