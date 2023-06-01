/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:51:26 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/21 18:04:27 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Returns the nth element
** Returns NULL if the element is not found
*/
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

/*
** Returns the value of the nth element
** Returns INT_MIN if the element is not found
*/
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

/*
** Returns the flag of the nth element
** Returns INT_MIN if the element is not found
*/
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

/*
** Returns the index of the element with the order value
** Returns -1 if the element is not found
*/
int	node_get_index_for_order(t_node *root, int order)
{
	int		count;
	t_node	*current;

	count = 0;
	current = root;
	while (current != NULL)
	{
		if (current->order == order)
			return (count);
		count++;
		current = current->next;
	}
	return (INT_MIN);
}
