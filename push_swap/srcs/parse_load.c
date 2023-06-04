/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:22:05 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/04 16:08:26 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Add new node to the end of list_a
*/
void	add_node(t_stack *stack, int *list_num, int i, int idx_num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		stack->error = 1;
	new_node->x = list_num[i];
	new_node->order = idx_num;
	new_node->flag = 0;
	new_node->keep = 0;
	new_node->next = NULL;
	node_insert_end(&stack->list_a, new_node);
	free(new_node);
}

/*
** Load arguments into stack->list_a and assign index number to each node
*/
void	load_arguments(t_stack *stack, int	*list_num)
{
	int		i;
	int		j;
	int		index_num;

	i = 0;
	while (stack->size > i)
	{
		j = 0;
		index_num = 1;
		while (stack->size > j)
		{
			if (list_num[i] > list_num[j])
				++index_num;
			j++;
		}
		add_node(stack, list_num, i, index_num);
		stack->size_a++;
		i++;
	}
}
