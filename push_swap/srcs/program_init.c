/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 07:47:20 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/04 14:24:42 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Count number of arguments
*/
// static int	count_args(char **args)
// {
// 	int	i;

// 	i = 0;
// 	while (args[i])
// 		i++;
// 	return (i - 1);
// }

/*
** Split arguments if string passed as argument
** Return must be freed with free by caller
*/
// static char	**argc_argv(int argc, char **argv, t_stack *stack)
// {
// 	char	**arguments;

// 	if (argc < 2)
// 		return (NULL);
// 	else if (argc == 2)
// 	{
// 		if (argv[1][0] == '\0')
// 			return (NULL);
// 		arguments = ft_split(argv[1], ' ');
// 		// arguments = string_to_number(argv[1], &stack->size);
// 		stack->size = count_args(arguments) + 1;
// 		return (arguments);
// 	}
// 	else
// 	{
// 		arguments = argv;
// 		stack->size = count_args(arguments);
// 		return (arguments);
// 	}
// }

/*
** Initialization of stack structure
** and load arguments into stack->list_a
** and assign index number to each node in stack->list_a
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
