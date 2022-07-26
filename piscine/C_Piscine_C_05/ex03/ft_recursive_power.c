/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:50:11 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/25 12:12:56 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power != 0)
		return (nb * ft_recursive_power(nb, power - 1));
	else
		return (1);
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
			printf("MINE : %d ^ %d = %d\n", i, j, ft_recursive_power(i, j));
			printf("-\n");
		}
		printf("--------------------------\n");
	}
}
*/