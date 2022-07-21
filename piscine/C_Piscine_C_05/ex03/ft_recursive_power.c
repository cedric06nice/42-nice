/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:50:11 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/20 18:13:16 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
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
int	main(void)
{
	printf("10 ^ 0 = 1\n");
	printf("10 ^ 0 = %d\n", ft_recursive_power(10, 0));
	printf("-\n");
	printf("6 ^ 1 = 6\n");
	printf("6 ^ 1 = %d\n", ft_recursive_power(6, 1));
	printf("-\n");
	printf("4 ^ 3 = 64\n");
	printf("4 ^ 3 = %d\n", ft_recursive_power(4, 3));
	printf("-\n");
	printf("3 ^ 6 = 729\n");
	printf("3 ^ 6 = %d\n", ft_recursive_power(3, 6));
	printf("-\n");
	printf("4 ^ 4 = 256\n");
	printf("4 ^ 4 = %d\n", ft_recursive_power(4, 4));
	printf("-\n");
	printf("0 ^ 0 = 1\n");
	printf("0 ^ 0 = %d\n", ft_recursive_power(0, 0));
	printf("-\n");
	printf("5 ^ -5 = 0\n");
	printf("5 ^ -5 = %d\n", ft_recursive_power(5, -5));
}
*/