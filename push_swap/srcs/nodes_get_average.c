/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_get_average.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:22:31 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/11 12:54:39 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	get_mid_a(t_stack *stack)
// {
// 	stack->min = get_min_a(stack);
// 	stack->max = get_max_a(stack);
// 	return ((stack->max - stack->min) / 2 + stack->min);
// }

// int	get_mid_b(t_stack *stack)
// {
// 	stack->min = get_min_a(stack);
// 	stack->max = get_max_a(stack);
// 	return ((stack->max - stack->min) / 2 + stack->min);
// }

void	set_average_values(t_stack *stack)
{
	// t_node	*temp_a;
	// t_node	*temp_b;
	// int		min_a = 1;
	// int		min_b = 1;
	// int		max_a = 0;
	// int		max_b = 0;

	// temp_a = stack->list_a;
	// temp_b = stack->list_b;
	// while (temp_a != NULL)
	// {
	// 	if (temp_a->order < min_a)
	// 		min_a = temp_a->order;
	// 	if (temp_a->order > max_a)
	// 		max_a = temp_a->order;
	// 	temp_a = temp_a->next;
	// }
	// while (temp_b != NULL)
	// {
	// 	if (temp_b->order < min_b)
	// 		min_b = temp_b->order;
	// 	if (temp_b->order > max_b)
	// 		max_b = temp_b->order;
	// 	temp_b = temp_b->next;
	// }
	// if (min_a < min_b)
	// 	stack->min = min_a;
	// else
	// 	stack->min = min_b;
	// if (max_a > max_b)
	// 	stack->max = max_a;
	// else
	// 	stack->max = max_b;
	get_min_a(stack);
	get_max_a(stack);
	get_min_b(stack);
	get_max_b(stack);
	if (stack->min_a < stack->min_b)
		stack->min = stack->min_a;
	else
		stack->min = stack->min_b;
	if (stack->max_a > stack->max_b)
		stack->max = stack->max_a;
	else
		stack->max = stack->max_b;
	stack->average = (stack->max - stack->min) / 2 + stack->min;
}

// int	nodes_median_values(t_node *list)
// {
// 	int	arr[nodes_count(list)];
// 	int	n;
// 	int	i;
// 	int	j;
// 	int	median;

// 	n = 0;
// 	while (list)
// 	{
// 		arr[n] = list->x;
// 		list = list->next;
// 		n++;
// 	}
// 	i = 1;
// 	while (i <= n - 1)
// 	{
// 		j = 1;
// 		while (j <= n - i)
// 		{
// 			if (arr[j - 1] > arr[j])
// 				ft_swap(&arr[j - 1], &arr[j], sizeof(int));
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (n % 2 == 0)
// 		median = (arr[n / 2 - 1] + arr[n / 2]) / 2;
// 	else
// 		median = arr[n / 2];
// 	return (median);
// }
