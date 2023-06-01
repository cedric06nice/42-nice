/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_shortest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:58:25 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/30 10:29:34 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Find the shortest route to insert the element in the stack
** Returns the index or -1 if the element is not found
*/
int	find_shortest_route_by_value(int value, t_node *node)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = node;
	while (tmp)
	{
		if (tmp->order == value)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}
