/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:11:13 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/17 00:06:38 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	load_in_stack_a(t_stack *stack, int x, int order, int flag, int group,
		int keep)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->x = x;
	new_node->order = order;
	new_node->flag = flag;
	new_node->group = group;
	new_node->keep = keep;
	node_insert_end(&stack->list_a, new_node);
}

void	load_in_stack_b(t_stack *stack, int x, int order, int flag, int group,
		int keep)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->x = x;
	new_node->order = order;
	new_node->flag = flag;
	new_node->group = group;
	new_node->keep = keep;
	node_insert_end(&stack->list_b, new_node);
}

t_stack	*load_test_values(void)
{
	t_stack	*stack;
	int		list[30] = {18, 12, 6, 24, 10, 11, 5, 4, 28, 16, 9, 27, 23, 17,
		3, 2, 7, 30, 1, 19, 14, 26, 8, 29, 22, 13, 15, 21, 20, 25};

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	init_stack(stack);
	stack->size = 30;
	load_arguments(stack, list);
	set_average_values(stack);
	return (stack);
}

int	main(void)
{
	t_stack	*stack;

	// t_stack	*stack = load_test_values();
	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (0);
	load_in_stack_a(stack, 24, 24, 0, 2, 0);
	load_in_stack_b(stack, 6, 6, 0, 0, 0);
	load_in_stack_b(stack, 12, 12, 0, 1, 0);
	load_in_stack_b(stack, 18, 18, 0, 1, 0);
	load_in_stack_b(stack, 10, 10, 0, 1, 0);
	load_in_stack_b(stack, 30, 30, 0, 3, 0);
	load_in_stack_b(stack, 32, 32, 0, 3, 0);
	load_in_stack_b(stack, 33, 33, 0, 3, 0);
	stack->max = 33;
	stack->min = 6;
	stack->average = 19;
	stack->size = 8;
	stack->size_a = 1;
	stack->size_b = 7;
	stack->min_a = 24;
	stack->max_a = 24;
	stack->min_b = 6;
	stack->max_b = 33;
	stack->group_min = 0;
	stack->group_max = 3;
	print_lists(*stack, 1);
	ft_printf("find_shortest_route_by_value(30): %d\n",
				find_shortest_route_by_value(30, stack->list_b));
	ft_printf("find_shortest_route_by_value(18): %d\n",
				find_shortest_route_by_value(18, stack->list_b));
	ft_printf("find_shortest_route_by_value(50): %d\n",
				find_shortest_route_by_value(50, stack->list_b));
	ft_printf("\n");
	ft_printf("find_shortest_route_by_group(1): %d\n",
				find_shortest_route_by_group(1, stack->list_b));
	ft_printf("find_shortest_route_by_group(3): %d\n",
				find_shortest_route_by_group(3, stack->list_b));
	ft_printf("find_shortest_route_by_group(2): %d\n",
				find_shortest_route_by_group(2, stack->list_b));
	ft_printf("\n");
	ft_printf("find_element_b_by_group(1): %d\n",
				find_element_b_by_group(stack, 1));
	ft_printf("find_element_b_by_group(3): %d\n",
				find_element_b_by_group(stack, 3));
	ft_printf("find_element_b_by_group(2): %d\n",
				find_element_b_by_group(stack, 2));
	ft_printf("\n");
	ft_printf("find_closest_in_b(1): %d\n",
				find_closest_group_in_b(stack, 1));
	ft_printf("find_closest_in_b(3): %d\n",
				find_closest_group_in_b(stack, 3));
	ft_printf("find_closest_in_b(2): %d\n",
				find_closest_group_in_b(stack, 2));
	b_shortest_route_group(stack, 1);
	print_lists(*stack, 1);
	return (0);
}
