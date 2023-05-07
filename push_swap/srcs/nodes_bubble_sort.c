/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_bubble_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:22:31 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/05 10:21:27 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_swap(int n, int *arr)
{
	int	i;
	int	j;

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
}

void	bubble_sort(t_stack *stack)
{
	int	*arr;
	int	n;

	n = 0;
	arr = (int *)malloc(sizeof(int) * nodes_count(stack->list_a));
	if (!arr)
		return ;
	while (stack->list_a)
	{
		arr[n] = stack->list_a->x;
		stack->list_a = stack->list_a->next;
		n++;
	}
	sort_swap(n, arr);
	free(arr);
}
