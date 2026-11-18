/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:30:20 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/21 17:10:00 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Find the element by value in the stack and return the position
** Returns 0 if the element is not found
*/
int	find_element_by_value(t_node *node, int value)
{
	t_node	*tmp;
	int		i;

	tmp = node;
	i = 0;
	while (tmp)
	{
		if (tmp->order == value)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}
