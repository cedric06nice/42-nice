/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:51:26 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/13 15:46:37 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*node_get_nth_elmt(t_node *root, int index)
{
	int		count;
	t_node	*current;

	count = 1;
	current = root;
	while (current != NULL)
	{
		if (count == index)
			return (current);
		count++;
		current = current->next;
	}
	return (NULL);
}

int	node_get_nth_val(t_node *root, int index)
{
	int		count;
	t_node	*current;

	count = 1;
	current = root;
	while (current != NULL)
	{
		if (count == index)
			return (current->x);
		count++;
		current = current->next;
	}
	return (INT_MIN);
}

int	node_get_nth_flag(t_node *root, int index)
{
	int		count;
	t_node	*current;

	count = 1;
	current = root;
	while (current != NULL)
	{
		if (count == index)
			return (current->flag);
		count++;
		current = current->next;
	}
	return (INT_MIN);
}
