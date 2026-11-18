/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 11:46:21 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/25 16:19:53 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_if_cmd_exists(char *cmd)
{
	if (ft_strcmp(cmd, "pa") != 0 && ft_strcmp(cmd, "pb") != 0 && ft_strcmp(cmd,
			"rra") != 0 && ft_strcmp(cmd, "rrb") != 0 && ft_strcmp(cmd,
			"rrr") != 0 && ft_strcmp(cmd, "ra") != 0 && ft_strcmp(cmd,
			"rb") != 0 && ft_strcmp(cmd, "rr") != 0 && ft_strcmp(cmd, "sa") != 0
		&& ft_strcmp(cmd, "sb") != 0 && ft_strcmp(cmd, "ss") != 0)
		return (1);
	else
		return (0);
}

/*
** Insert the command at the end of the list
*/
void	add_command(t_stack **stack, char *cmd)
{
	t_cmd	*new_node;
	t_cmd	*current;

	current = NULL;
	if (stack == NULL || cmd == NULL)
		return ;
	if (check_if_cmd_exists(cmd) == 1)
		return ;
	new_node = (t_cmd *)malloc(sizeof(t_cmd));
	if (new_node == NULL)
		return ;
	new_node->cmd = (char *)malloc((ft_strlen(cmd) + 1) * sizeof(char));
	if (new_node->cmd == NULL)
		return (free(new_node));
	ft_strlcpy(new_node->cmd, cmd, ft_strlen(cmd) + 1);
	new_node->next = NULL;
	if ((*stack)->commands == NULL)
		(*stack)->commands = new_node;
	else
	{
		current = (*stack)->commands;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}
