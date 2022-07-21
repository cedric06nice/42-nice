/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:34:24 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/20 17:35:21 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
int	ft_iterative_factorial(int nb)
{
	int	i;

	i = nb - 1;
	if (nb == 0)
		return (1);
	while (i > 0)
	{
		nb *= i;
		i--;
	}
	return (nb);
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