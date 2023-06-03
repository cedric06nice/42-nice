/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_reduce.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:10:21 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/01 22:54:23 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	delete_command(t_cmd **headRef, t_cmd *node)
{
	t_cmd	*curr;
	t_cmd	*prev;

	curr = *headRef;
	prev = NULL;
	if (curr != NULL && curr == node)
	{
		*headRef = curr->next;
		free(curr->cmd);
		free(curr);
		return ;
	}
	while (curr != NULL && curr != node)
	{
		prev = curr;
		curr = curr->next;
	}
	if (curr == NULL)
		return ;
	prev->next = curr->next;
	free(curr->cmd);
	free(curr);
}

static t_cmd	*new_command(char *cmd)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (new == NULL)
		return (NULL);
	new->cmd = (char *)malloc((ft_strlen(cmd) + 1) * sizeof(char));
	if (new->cmd == NULL)
		return (NULL);
	ft_strlcpy(new->cmd, cmd, ft_strlen(cmd) + 1);
	new->next = NULL;
	return (new);
}

static void	insert_new_command(t_cmd **headRef, t_cmd *node, char *new_cmd)
{
	t_cmd	*temp;
	t_cmd	*next;
	t_cmd	*new_node;

	temp = *headRef;
	new_node = new_command(new_cmd);
	if (temp != NULL && temp == node)
	{
		*headRef = new_node;
		new_node->next = temp;
		return ;
	}
	while (temp != NULL && temp != node)
	{
		temp = temp->next;
		next = temp->next;
	}
	if (temp == NULL)
		return ;
	temp->next = new_node;
	new_node->next = next;
}

static void	reducer(t_cmd **all, t_cmd *prev, t_cmd *next)
{
	if ((!ft_strcmp(prev->next->cmd, "sa") && !ft_strcmp(next->next->cmd, "sb"))
		|| (!ft_strcmp(prev->next->cmd, "sb") && !ft_strcmp(next->next->cmd,
				"sa")))
	{
		delete_command(all, next->next);
		delete_command(all, prev->next);
		insert_new_command(all, prev, "ss");
	}
	if ((!ft_strcmp(prev->next->cmd, "ra") && !ft_strcmp(next->next->cmd, "rb"))
		|| (!ft_strcmp(prev->next->cmd, "rb") && !ft_strcmp(next->next->cmd,
				"ra")))
	{
		delete_command(all, next->next);
		delete_command(all, prev->next);
		insert_new_command(all, prev, "rr");
	}
	if ((!ft_strcmp(prev->next->cmd, "rra") && !ft_strcmp(next->next->cmd,
				"rrb")) || (!ft_strcmp(prev->next->cmd, "rrb")
			&& !ft_strcmp(next->next->cmd, "rra")))
	{
		delete_command(all, next->next);
		delete_command(all, prev->next);
		insert_new_command(all, prev, "rrr");
	}
}

/*
** Reduce commands to minimize the number of operations
*/
void	reduce_commands(t_stack *stack)
{
	t_cmd	*cmds;
	t_cmd	*prev;
	t_cmd	*next;

	cmds = stack->commands;
	while (cmds && cmds->next->next->next->next)
	{
		prev = cmds->next->next;
		next = cmds->next->next->next;
		reducer(&stack->commands, prev, next);
		cmds = cmds->next;
	}
}
