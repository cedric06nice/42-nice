/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 10:14:33 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/13 15:44:37 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** (rotate a)
** Décale d’une position vers le haut tous les élements de la pile a.
** Le premier élément devient le dernier.
*/
void	ra(t_stack *stack)
{
	if (!stack->list_a)
		return ;
	node_insert_end(&stack->list_a, stack->list_a);
	node_remove_fst(&stack->list_a);
	insert_command(&stack, "ra");
}

/*
** (rotate b)
** Décale d’une position vers le haut tous les élements de la pile b.
** Le premier élément devient le dernier.
*/
void	rb(t_stack *stack)
{
	if (!stack->list_b)
		return ;
	node_insert_end(&stack->list_b, stack->list_b);
	node_remove_fst(&stack->list_b);
	insert_command(&stack, "rb");
}

/*
** ra et rb en même temps.
*/
void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}
