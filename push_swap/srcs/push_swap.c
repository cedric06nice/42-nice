/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:37:06 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/13 15:00:37 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Split list_a to list_b to the middle
*/
void	split_list(t_stack *stack)
{
	while (stack->size_a > stack->size / 2)
	{
		if (stack->list_a->order <= stack->size / 2)
			pb(stack);
		else
			ra(stack);
	}
}

/*
** Merge list_b to list_a
*/
void	merge_list(t_stack *stack)
{
	while (stack->size_b > 0)
		pa(stack);
}

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
		return (free(stack), -1);
	}
	sort(stack);
	reduce_commands(stack);
	print_commands(*stack);
	node_delete(&stack->list_a);
	node_delete(&stack->list_b);
	return (free(stack), 0);
}
