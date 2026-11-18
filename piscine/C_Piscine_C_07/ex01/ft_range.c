/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:18:27 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/26 10:29:45 by cpugnair         ###   ########.fr       */
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
