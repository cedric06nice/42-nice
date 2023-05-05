/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:34:34 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/05 08:49:37 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Print the commands to the standard output.
*/
void	print_commands(t_stack stack)
{
	while (stack.commands)
	{
		ft_putendl_fd(stack.commands->cmd, 1);
		stack.commands = stack.commands->next;
	}
}

void	print_extra_info(t_stack stack)
{
	t_cmd	*cmd;

	ft_printf("\tMin       : %d\n", stack.min);
	ft_printf("\tMax       : %d\n", stack.max);
	ft_printf("\tAverage   : %d\n", stack.average);
	ft_printf("\tIndex     : %d\n", stack.index);
	ft_printf("\tFlag      : %d\n", stack.flag);
	ft_printf("\tSize      : %d\n", stack.size);
	ft_printf("\tHas loops : %d\n", nodes_has_loops(stack.list_a));
	ft_printf("\tError     : %d\n", stack.error);
	ft_printf("\tCommands  : \t");
	cmd = stack.commands;
	while (cmd)
	{
		ft_printf("%s ", cmd->cmd);
		cmd = cmd->next;
	}
	ft_printf("\n");
}

void	print_lists(t_stack stack, int extra)
{
	t_node	*a;
	t_node	*b;

	a = stack.list_a;
	b = stack.list_b;
	ft_printf("\033[1;33m\n\n");
	while (a || b)
	{
		if (a)
		{
			ft_printf("\t%d (%d) [%d]", a->x, a->order, a->flag);
			a = a->next;
		}
		else
			ft_printf("\t");
		if (b)
		{
			ft_printf("\t\t%d (%d) [%d]", b->x, b->order, b->flag);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("\t-----\t\t\t-----\n");
	ft_printf("\ta (%d)\t\t\tb (%d)\n\n\033[0m", stack.size_a, stack.size_b);
	if (extra)
		print_extra_info(stack);
}

void	print_linear(t_stack stack, int extra)
{
	t_node	*a;
	t_node	*b;

	a = stack.list_a;
	b = stack.list_b;
	ft_printf("\033[1;33m\n");
	ft_printf("a = ");
	while (a)
	{
		ft_printf("%d (%d)  ", a->x, a->order);
		a = a->next;
	}
	ft_printf("\n");
	ft_printf("b = ");
	while (b)
	{
		ft_printf("%d (%d)  ", b->x, b->order);
		b = b->next;
	}
	ft_printf("\n\033[0m");
	if (extra)
		print_extra_info(stack);
}

void	print_test(char *str)
{
	int	i;

	i = ft_strlen(str);
	ft_printf("\n\033[1;34m*-----");
	while (i-- > 0)
		ft_printf("-");
	ft_printf("-----*\n");

	i = ft_strlen(str);
	ft_printf("|     ");
	ft_printf("%s", str);
	ft_printf("     |\n");

	i = ft_strlen(str);
	ft_printf("*-----");
	while (i-- > 0)
		ft_printf("-");
	ft_printf("-----*\033[0m\n");
}
