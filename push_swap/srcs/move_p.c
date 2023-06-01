/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:38:45 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/31 22:24:40 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** (push a)
** Prend le premier élément au sommet de b et le met sur a.
** Ne fait rien si b est vide.
*/
void	pa(t_stack *stack)
{
	if (!stack->list_b)
		return ;
	// ft_printf("pa - test 1\n");
	node_insert_beg(&stack->list_a, stack->list_b);
	// ft_printf("pa - test 2\n");
	node_remove_fst(&stack->list_b);
	// ft_printf("pa - test 3\n");
	stack->size_a++;
	// ft_printf("pa - test 4\n");
	get_min_a(stack);
	// ft_printf("pa - test 5\n");
	get_max_a(stack);
	// ft_printf("pa - test 6\n");
	stack->size_b--;
	// ft_printf("pa - test 7\n");
	get_min_b(stack);
	// ft_printf("pa - test 8\n");
	get_max_b(stack);
	// ft_printf("pa - test 9\n");
	add_command(&stack, "pa");
	// ft_printf("pa - test 10\n");
	// print_lists(*stack, 1);
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
	node_insert_beg(&stack->list_b, stack->list_a);
	node_remove_fst(&stack->list_a);
	stack->size_a--;
	get_min_a(stack);
	get_max_a(stack);
	stack->size_b++;
	get_min_b(stack);
	get_max_b(stack);
	add_command(&stack, "pb");
}
