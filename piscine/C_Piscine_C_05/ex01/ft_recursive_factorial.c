/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:12:05 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/20 17:35:29 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
int	ft_iterative_factorial(int nb)
{
	if (nb == 0)
		return (1);
	return (nb * ft_iterative_factorial(nb - 1));
}
/*
int	main(void)
{
	printf("Factorielle 0 = 1\n");
	printf("Factorielle 0 = %d\n", ft_iterative_factorial(0));
	printf("-\n");
	printf("Factorielle 1 = 1\n");
	printf("Factorielle 1 = %d\n", ft_iterative_factorial(1));
	printf("-\n");
	printf("Factorielle 2 = 2\n");
	printf("Factorielle 2 = %d\n", ft_iterative_factorial(2));
	printf("-\n");
	printf("Factorielle 3 = 6\n");
	printf("Factorielle 3 = %d\n", ft_iterative_factorial(3));
	printf("-\n");
	printf("Factorielle 4 = 24\n");
	printf("Factorielle 4 = %d\n", ft_iterative_factorial(4));
	printf("-\n");
	printf("Factorielle 5 = 120\n");
	printf("Factorielle 5 = %d\n", ft_iterative_factorial(5));
	printf("-\n");
	printf("Factorielle 6 = 720\n");
	printf("Factorielle 6 = %d\n", ft_iterative_factorial(6));
}
*/