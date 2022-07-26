/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:04:00 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/26 06:48:14 by cpugnair         ###   ########.fr       */
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
