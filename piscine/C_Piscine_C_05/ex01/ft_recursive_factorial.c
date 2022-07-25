/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:12:05 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/25 08:40:22 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}
/*
#include <stdio.h>

int	main(void)
{
	printf("Factorielle 0 = 1\n");
	printf("Factorielle 0 = %d\n", ft_recursive_factorial(0));
	printf("-\n");
	printf("Factorielle 1 = 1\n");
	printf("Factorielle 1 = %d\n", ft_recursive_factorial(1));
	printf("-\n");
	printf("Factorielle 2 = 2\n");
	printf("Factorielle 2 = %d\n", ft_recursive_factorial(2));
	printf("-\n");
	printf("Factorielle 3 = 6\n");
	printf("Factorielle 3 = %d\n", ft_recursive_factorial(3));
	printf("-\n");
	printf("Factorielle 4 = 24\n");
	printf("Factorielle 4 = %d\n", ft_recursive_factorial(4));
	printf("-\n");
	printf("Factorielle 5 = 120\n");
	printf("Factorielle 5 = %d\n", ft_recursive_factorial(5));
	printf("-\n");
	printf("Factorielle 6 = 720\n");
	printf("Factorielle 6 = %d\n", ft_recursive_factorial(6));
}
*/