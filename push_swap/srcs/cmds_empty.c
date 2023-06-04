/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_empty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:20:13 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/04 15:54:38 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Free commands linked list
*/
void	empty_commands(t_cmd **commands)
{
	t_cmd	*curr;
	t_cmd	*next;

	curr = *commands;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr->cmd);
		free(curr);
		curr = next;
	}
	*commands = NULL;
}
