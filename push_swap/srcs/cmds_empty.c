/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_empty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:20:13 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/25 16:22:29 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	empty_commands(t_cmd **commands)
{
	t_cmd	*tmp;

	if (commands == NULL || *commands == NULL)
		return ;
	while (*commands != NULL)
	{
		tmp = *commands;
		*commands = (*commands)->next;
		free(tmp->cmd);
		free(tmp);
	}
	*commands = NULL;
}
