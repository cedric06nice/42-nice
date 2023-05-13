/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 10:25:18 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/13 12:56:19 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** (reverse rotate a)
** Décale d’une position vers le bas tous les élements de la pile a.
** Le dernier élément devient le premier.
*/
void	rra(t_stack *stack)
{
	t_node	*tmp;

	if (!stack->list_a || stack->size_a < 2)
		return ;
	else
	{
		tmp = node_get_nth_elmt(stack->list_a, stack->size_a);
		node_insert_beg(&stack->list_a, tmp);
		node_remove_lst(&stack->list_a);
		insert_command(&stack, "rra");
	}
}

/*
** (reverse rotate b)
** Décale d’une position vers le bas tous les élements de la pile b.
** Le dernier élément devient le premier.
*/
void	rrb(t_stack *stack)
{
	t_node	*tmp;

	if (!stack->list_b || stack->size_b < 2)
		return ;
	else
	{
		tmp = node_get_nth_elmt(stack->list_b, stack->size_b);
		node_insert_beg(&stack->list_b, tmp);
		node_remove_lst(&stack->list_b);
		insert_command(&stack, "rrb");
	}
}

/*
** rra et rrb en même temps.
*/
void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}
