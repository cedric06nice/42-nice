/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:52:29 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/04 16:07:03 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Check if the list is sorted
** Return 0 if sorted, -1 if not
*/
int	node_is_sorted(t_node **list, char sort)
{
	t_node	*lst;

	lst = *list;
	if (sort == '<')
	{
		while (lst->next != NULL)
		{
			if (lst->order > lst->next->order)
				return (-1);
			lst = lst->next;
		}
	}
	else if (sort == '>')
	{
		while (lst->next != NULL)
		{
			if (lst->order < lst->next->order)
				return (-1);
			lst = lst->next;
		}
	}
	else
		return (-1);
	return (0);
}
