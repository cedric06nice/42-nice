/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:25:46 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/25 08:40:36 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = power - 1;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (i > 0)
	{
		nb *= nb;
		i--;
	}
	return (nb);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("10 ^ 0 = 1\n");
	printf("10 ^ 0 = %d\n", ft_iterative_power(10, 0));
	printf("-\n");
	printf("6 ^ 1 = 6\n");
	printf("6 ^ 1 = %d\n", ft_iterative_power(6, 1));
	printf("-\n");
	printf("4 ^ 3 = 64\n");
	printf("4 ^ 3 = %d\n", ft_iterative_power(4, 3));
	printf("-\n");
	printf("3 ^ 6 = 729\n");
	printf("3 ^ 6 = %d\n", ft_iterative_power(3, 6));
	printf("-\n");
	printf("4 ^ 4 = 256\n");
	printf("4 ^ 4 = %d\n", ft_iterative_power(4, 4));
	printf("-\n");
	printf("0 ^ 0 = 1\n");
	printf("0 ^ 0 = %d\n", ft_iterative_power(0, 0));
	printf("-\n");
	printf("5 ^ -5 = 0\n");
	printf("5 ^ -5 = %d\n", ft_iterative_power(5, -5));
}
*/