/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:18:27 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/25 18:01:05 by cpugnair         ###   ########.fr       */
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
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	main(void)
{
	int	i;
	int	min;
	int	max;
	int	*test;

	i = 0;
	min = 10;
	max = 20;
	test = ft_range(min, max);
	while (i < max - min)
	{
		printf("[ %d ] ", test[i]);
		i++;
	}
	free(test);
}
*/