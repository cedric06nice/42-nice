/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 11:46:21 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/13 12:30:24 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_if_cmd_exists(char *cmd)
{
	if (ft_strcmp(cmd, "pa") != 0 && ft_strcmp(cmd, "pb") != 0
		&& ft_strcmp(cmd, "rra") != 0 && ft_strcmp(cmd, "rrb") != 0
		&& ft_strcmp(cmd, "rrr") != 0
		&& ft_strcmp(cmd, "ra") != 0 && ft_strcmp(cmd, "rb") != 0
		&& ft_strcmp(cmd, "rr") != 0
		&& ft_strcmp(cmd, "sa") != 0 && ft_strcmp(cmd, "sb") != 0
		&& ft_strcmp(cmd, "ss") != 0)
		return (1);
	else
		return (0);
}

static void	set_command(t_cmd *cmd, char *cmd_str)
{
	cmd->cmd = cmd_str;
	cmd->next = NULL;
}

/*
** Insert the command at the end of the list
*/
void	insert_command(t_stack **stack, char *cmd)
{
	t_cmd	*root;
	t_cmd	*new_cmd;
	t_cmd	*curr;

	if (stack == NULL || cmd == NULL)
		return ;
	if (check_if_cmd_exists(cmd) == 1)
		return ;
	root = (*stack)->commands;
	if ((*stack)->commands == NULL)
	{
		(*stack)->commands = malloc(sizeof(t_cmd));
		if ((*stack)->commands == NULL)
			exit (1);
		set_command((*stack)->commands, cmd);
		return ;
	}
	new_cmd = malloc(sizeof(t_cmd));
	if (new_cmd == NULL)
		exit (1);
	set_command(new_cmd, cmd);
	curr = root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_cmd;
}

static void	reducer(t_cmd *prev, t_cmd *tmp)
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
