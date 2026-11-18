/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:53:05 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/25 12:26:27 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i < 46341 && i * i < nb)
		i++;
	if (i * i != nb)
		return (0);
	return (i);
}
/*
#include <stdio.h>
#include <math.h>

int	main(void)
{
	for (int i = -5; i < 50; i++)
	{
		printf("   SQRT %d = %f\n", i, sqrt(i));
		printf("FT_SQRT %d = %d\n", i, ft_sqrt(i));
		printf("-\n");
	}
}
*/