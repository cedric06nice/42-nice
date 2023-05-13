/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:31:40 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/13 12:52:45 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	node_count(t_node *root)
{
	if (root == NULL)
		return (0);
	return (1 + node_count(root->next));
}

int	node_check_dup(t_node *root)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = root;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		while (tmp2 != NULL)
		{
			if (tmp->x == tmp2->x)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	node_has_loops(t_node *root)
{
	t_node	*slow;
	t_node	*fast;

	slow = root;
	fast = root;
	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (1);
	}
	return (0);
}
