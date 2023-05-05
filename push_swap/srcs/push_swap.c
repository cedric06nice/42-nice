/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:37:06 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/05 09:24:09 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nodes_is_sorted(t_node **list, char sort)
{
	t_node	*lst;

	lst = *list;
	if (sort == '<')
	{
		while (lst->next != NULL)
		{
			if (lst->order > lst->next->order)
				return (-1);
			lst = lst->next;
		}
	}
	else if (sort == '>')
	{
		while (lst->next != NULL)
		{
			if (lst->order < lst->next->order)
				return (-1);
			lst = lst->next;
		}
	}
	else
		return (-1);
	return (0);
}

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

void	reducer(t_cmd *prev, t_cmd *tmp)
{
	if ((!ft_strcmp(prev->cmd, "sa") && !ft_strcmp(tmp->cmd, "sb"))
		|| (!ft_strcmp(prev->cmd, "sb") && !ft_strcmp(tmp->cmd, "sa")))
	{
		prev->cmd = "ss";
		prev->next = tmp->next;
	}
	if ((!ft_strcmp(prev->cmd, "ra") && !ft_strcmp(tmp->cmd, "rb"))
		|| (!ft_strcmp(prev->cmd, "rb") && !ft_strcmp(tmp->cmd, "ra")))
	{
		prev->cmd = "rr";
		prev->next = tmp->next;
	}
	if ((!ft_strcmp(prev->cmd, "rra") && !ft_strcmp(tmp->cmd, "rrb"))
		|| (!ft_strcmp(prev->cmd, "rrb") && !ft_strcmp(tmp->cmd, "rra")))
	{
		prev->cmd = "rrr";
		prev->next = tmp->next;
	}
}

/*
** Reduce commands to minimize the number of operations
*/
void	reduce_commands(t_stack *stack)
{
	t_cmd	*tmp;
	t_cmd	*prev;

	tmp = stack->commands;
	while (tmp)
	{
		if (!tmp->next)
			return ;
		prev = tmp;
		tmp = tmp->next;
		reducer(prev, tmp);
	}
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
	nodes_delete(&stack->list_a);
	nodes_delete(&stack->list_b);
	return (free(stack), 0);
}
