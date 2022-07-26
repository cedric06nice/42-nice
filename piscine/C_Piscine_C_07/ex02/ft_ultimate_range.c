/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:04:00 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/26 10:00:25 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	*range = NULL;
	if (min >= max)
		return (0);
	if (min < -2147483648 || max > 2147483647 || (max - min) > 2147483647)
		return (-1);
	*range = malloc(sizeof(int) * (max - min));
	if (*range == NULL)
		return (-1);
	while (i < max - min)
	{
		*range[i] = min + i;
		i++;
	}
	return (i);
}

#include <stdio.h>

int	main(void)
{
	int *range;

	printf("Warn: Any segfault will mean that arrays are not correctly allocated\n");

	printf("            5 => %d\n", ft_ultimate_range(&range, 0, 5));
	printf("0, 1, 2, 3, 4 => %d, %d, %d, %d, %d\n", range[0], range[1], range[2], range[3], range[4]);
	
	printf("            0 => %d\n", ft_ultimate_range(&range, 3, 3));
	
	printf("            2 => %d\n", ft_ultimate_range(&range, -1, 1));
	printf("        -1, 0 => %d, %d", range[0], range[1]);
}
