/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_bubble_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:22:31 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/05 09:20:41 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_stack *stack)
{
	int	arr[nodes_count(stack->list_a)];
	int	n;
	int	i;
	int	j;

	n = 0;
	while (stack->list_a)
	{
		arr[n] = stack->list_a->x;
		stack->list_a = stack->list_a->next;
		n++;
	}
	i = 1;
	while (i <= n - 1)
	{
		j = 1;
		while (j <= n - i)
		{
			if (arr[j - 1] > arr[j])
				ft_swap(&arr[j - 1], &arr[j], sizeof(int));
			j++;
		}
		i++;
	}
	// ft_printf("sorted array: ");
	// i = 0;
	// while (i < n)
	// {
	// 	ft_printf("%d ", arr[i]);
	// 	i++;
	// }
	// ft_printf("\n");
}
