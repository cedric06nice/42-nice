/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:25:46 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/25 12:01:12 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	num;

	num = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power > 1)
	{
		num *= nb;
		power--;
	}
	return (num);
}
/*
#include <stdio.h>
#include <math.h>

int	main(void)
{
	for (int i = -10; i < 10; i++)
	{
		for (int j = -10; j < 10; j++)
		{
			printf("POW  : %d ^ %d = %d\n", i, j, (int)pow(i, j));
			printf("MINE : %d ^ %d = %d\n", i, j, ft_iterative_power(i, j));
			printf("-\n");
		}
		printf("--------------------------\n");
	}
}
*/