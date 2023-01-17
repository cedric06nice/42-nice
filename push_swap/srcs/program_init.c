/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 07:47:20 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/16 22:02:29 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Count number of arguments
*/
static int 	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i - 1);
}

/*
** Check if there are duplicates in the list of numbers
*/
static int	check_duplicates(int *arr, int num)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == num)
			return (1);
		i++;
	}
	return (0);
}

/*
** Transform arguments into list of numbers
*/
static int	*transform(char **arguments, int i, int count_args)
{
	int		*list_num;
	int		j;
	int		k;
	int		num;

	list_num = malloc(sizeof(int) * count_args);
	k = 0;
	while (arguments[i])
	{
		j = 0;
		while (arguments[i][j])
		{
			if (j == 0
				&& (ft_isdigit(arguments[i][j])
					|| ((arguments[i][j] == '-' || arguments[i][j] == '+')
						&& ft_isdigit(arguments[i][j + 1]))))
				j++;
			else if (ft_isdigit(arguments[i][j]))
				j++;
			else
				return (NULL);
		}
		num = ft_atoi(arguments[i]);
		// ft_putendl_fd(ft_itoa(num), 1);
		if (num > 2147483647 || num < -2147483648)
			return (NULL);
		list_num[k++] = num;
		i++;
	}
	check_duplicates(list_num, 1);
	return (list_num);
}

/*
** Load arguments into stack->list_a and assign index number to each node
*/
static void load_arguments(t_stack *stack, int	*list_num)
{
	int		i;
	int		j;
	int		index_num;
	t_node	*new_node;

	i = 0;
	while (stack->size > i)
	{
		j = 0;
		index_num = 1;
		while (stack->size > j)
		{
			if (list_num[i] > list_num[j])
				++index_num;
			j++;
		}
		new_node = malloc(sizeof(t_node));
		if (new_node == NULL)
			return ;
		new_node->x = list_num[i];
		new_node->order = index_num;
		new_node->flag = 0;
		new_node->next = NULL;
		nodes_insert_end(&stack->list_a, new_node);
		free(new_node);
		stack->size_a++;
		i++;
	}
}

/*
** First initialization of stack structure
*/
static void	first_init(t_stack *stack)
{
	stack->list_a = NULL;
	stack->list_b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->size = 0;
	stack->min = 1;
	stack->max = 0;
	stack->average = 0;
	stack->index = 1;
	stack->commands = NULL;
	stack->error = 0;
}

/*
** Initialization of stack structure
** and load arguments into stack->list_a
** and assign index number to each node in stack->list_a
*/
t_stack		*init(int argc, char **argv)
{
	int		i;
	char	**arguments;
	t_stack	*stack;
	int		*list_num;

	i = 0;
	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	first_init(stack);
	if (argc < 2)
		// return (stack->error = 1, stack);
		return (NULL);
	else
	if (argc == 2)
	{
		if (argv[1][0] == '\0')
			return (stack->error = 1, stack);
		arguments = ft_split(argv[1], ' ');
		stack->size = count_args(arguments) + 1;
	}
	else
	{
		i = 1;
		arguments = argv;
		stack->size = count_args(arguments);
	}
	list_num = transform(arguments, i, stack->size);
	if (list_num == NULL)
		return (stack->error = 1, stack);
	load_arguments(stack, list_num);
	set_average_values(stack);
	if (argc == 2)
		free(arguments);
	if (nodes_check_duplicate(stack->list_a) == 1)
		return (stack->error = 1, stack);
	return (stack);
}
