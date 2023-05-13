/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:28:33 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/11 12:54:33 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** (swap a)
** Intervertit les 2 premiers éléments au sommet de la pile a.
** Ne fait rien s’il n’y en a qu’un ou aucun.
*/
void	sa(t_stack *stack)
{
	t_node	*node_1;
	t_node	*node_2;

	if (stack->size_a < 2)
		return ;
	node_1 = malloc(sizeof(t_node));
	node_2 = malloc(sizeof(t_node));
	if (!node_1 || !node_2)
		return ;
	node_1->x = nodes_get_nth_element(stack->list_a, 1)->x;
	node_1->order = nodes_get_nth_element(stack->list_a, 1)->order;
	node_1->flag = nodes_get_nth_element(stack->list_a, 1)->flag;
	node_2->x = nodes_get_nth_element(stack->list_a, 2)->x;
	node_2->order = nodes_get_nth_element(stack->list_a, 2)->order;
	node_2->flag = nodes_get_nth_element(stack->list_a, 2)->flag;
	nodes_remove_first(&stack->list_a);
	nodes_remove_first(&stack->list_a);
	nodes_insert_beginning(&stack->list_a, node_1);
	nodes_insert_beginning(&stack->list_a, node_2);
	nodes_insert_command(&stack, "sa");
}

/*
** (swap b)
** Intervertit les 2 premiers éléments au sommet de la pile b.
** Ne fait rien s’il n’y en a qu’un ou aucun.
*/
void	sb(t_stack *stack)
{
	t_node	*node_1;
	t_node	*node_2;

	if (stack->size_b < 2)
		return ;
	node_1 = malloc(sizeof(t_node));
	node_2 = malloc(sizeof(t_node));
	if (!node_1 || !node_2)
		return ;
	node_1->x = nodes_get_nth_element(stack->list_b, 1)->x;
	node_1->order = nodes_get_nth_element(stack->list_b, 1)->order;
	node_1->flag = nodes_get_nth_element(stack->list_b, 1)->flag;
	node_2->x = nodes_get_nth_element(stack->list_b, 2)->x;
	node_2->order = nodes_get_nth_element(stack->list_b, 2)->order;
	node_2->flag = nodes_get_nth_element(stack->list_b, 2)->flag;
	nodes_remove_first(&stack->list_b);
	nodes_remove_first(&stack->list_b);
	nodes_insert_beginning(&stack->list_b, node_1);
	nodes_insert_beginning(&stack->list_b, node_2);
	nodes_insert_command(&stack, "sb");
}

/*
** sa et sb en même temps.
*/
void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}
