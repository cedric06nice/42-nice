/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:31:40 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/04 15:40:59 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Count and return the number of nodes in the list
*/
int	node_count(t_node *root)
{
	if (root == NULL)
		return (0);
	return (1 + node_count(root->next));
}

/*
** Return 1 if there is a duplicate in the list, 0 otherwise
*/
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
