/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:22:05 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/17 00:34:12 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	spliter(int size, int nb)
{
	if (size > 400)
		return (nb / (size / 15));
	if (size > 80)
		return (nb / (size / 6));
	if (size > 50)
		return (nb / (size / 4));
	if (size > 20)
		return (nb / (size / 3));
	return (size);
}

static void	add_node(t_stack *stack, int *list_num, int i, int index_num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		stack->error = 1;
	new_node->x = list_num[i];
	new_node->order = index_num;
	new_node->flag = 0;
	new_node->group = spliter(stack->size, list_num[i]);
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
