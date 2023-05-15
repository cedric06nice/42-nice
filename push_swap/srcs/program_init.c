/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 07:47:20 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/14 04:48:06 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Count number of arguments
*/
static int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i - 1);
}

static char	**argc_argv(int argc, char **argv, t_stack *stack)
{
	char	**arguments;

	if (argc < 2)
		return (NULL);
	else if (argc == 2)
	{
		if (argv[1][0] == '\0')
			return (NULL);
		arguments = ft_split(argv[1], ' ');
		stack->size = count_args(arguments) + 1;
		return (arguments);
	}
	else
	{
		arguments = argv;
		stack->size = count_args(arguments);
		return (arguments);
	}
}

/*
** Initialization of stack structure
** and load arguments into stack->list_a
** and assign index number to each node in stack->list_a
*/
t_stack	*init(int argc, char **argv)
{
	int		i;
	char	**arguments;
	t_stack	*stack;
	int		*list_num;

	i = 0;
	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	init_stack(stack);
	arguments = argc_argv(argc, argv, stack);
	if (arguments == NULL)
		return (stack->error = 1, stack);
	if (argc > 2)
		i = 1;
	list_num = transform_args(arguments, i, stack->size);
	if (list_num == NULL)
		return (stack->error = 1, stack);
	load_arguments(stack, list_num);
	set_average_values(stack);
	if (argc == 2)
		free(arguments);
	if (node_check_dup(stack->list_a) == 1)
		return (stack->error = 1, stack);
	return (stack);
}
