/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:18:27 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/26 09:43:01 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*res;

	i = 0;
	res = NULL;
	if (min >= max)
		return (NULL);
	res = malloc(sizeof(int) * (max - min));
	while (i < max - min)
	{
		res[i] = min + i;
		i++;
	}
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	int *range;

	printf("Warn: Don't forget to check that the array is of the correct size manually ! Can't know size of `malloc` arrays\n");
	printf("Warn: Any segfault will mean that arrays are not correctly allocated\n");

	range = ft_range(0, 5);
	printf("0, 1, 2, 3, 4 = %d, %d, %d, %d, %d\n", range[0], range[1], range[2], range[3], range[4]);
	
	range = ft_range(3, 3);
	
	range = ft_range(-1, 1);
	printf("        -1, 0 = %d, %d\n", range[0], range[1]);
}
*/