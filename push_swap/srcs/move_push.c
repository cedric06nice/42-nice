/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:38:45 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/07 12:08:28 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** (push a)
** Prend le premier élément au sommet de b et le met sur a.
** Ne fait rien si b est vide.
*/
void	pa(t_stack *stack)
{
	if (!stack->list_b)
		return ;
	nodes_insert_beginning(&stack->list_a, stack->list_b);
	nodes_remove_first(&stack->list_b);
	stack->size_a++;
	get_min_a(stack);
	get_max_a(stack);
	stack->size_b--;
	get_min_b(stack);
	get_max_b(stack);
	nodes_insert_command(&stack, "pa");
}

/*
** (push b)
** Prend le premier élément au sommet de a et le met sur b.
** Ne fait rien si a est vide.
*/
void	pb(t_stack *stack)
{
	if (!stack->list_a)
		return ;
	nodes_insert_beginning(&stack->list_b, stack->list_a);
	nodes_remove_first(&stack->list_a);
	stack->size_a--;
	get_min_a(stack);
	get_max_a(stack);
	stack->size_b++;
	get_min_b(stack);
	get_max_b(stack);
	nodes_insert_command(&stack, "pb");
}
