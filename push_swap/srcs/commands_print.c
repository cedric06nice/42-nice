/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:11:45 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/13 12:33:43 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
