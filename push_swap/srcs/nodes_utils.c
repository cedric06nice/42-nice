/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:31:40 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/13 00:35:24 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		nodes_count(t_node *root)
{
	if (root == NULL)
		return (0);
	return (1 + nodes_count(root->next));
}

int		nodes_check_duplicate(t_node *root)
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

t_node	*nodes_get_nth_element(t_node *root, int index)
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

int		nodes_get_nth_value(t_node *root, int index)
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

int		get_nth_flag(t_node *root, int index)
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

int		nodes_has_loops(t_node *root)
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
