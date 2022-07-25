/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:15:37 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/25 08:41:09 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
/*
#include <stdio.h>

int	main(void)
{
	printf("F-5 = -1\n");
	printf("F-5 = %d\n", ft_fibonacci(-5));
	printf("-\n");
	printf("F0 = 0\n");
	printf("F0 = %d\n", ft_fibonacci(0));
	printf("-\n");
	printf("F1 = 1\n");
	printf("F1 = %d\n", ft_fibonacci(1));
	printf("-\n");
	printf("F2 = 1\n");
	printf("F2 = %d\n", ft_fibonacci(2));
	printf("-\n");
	printf("F3 = 2\n");
	printf("F3 = %d\n", ft_fibonacci(3));
	printf("-\n");
	printf("F4 = 3\n");
	printf("F4 = %d\n", ft_fibonacci(4));
	printf("-\n");
	printf("F5 = 5\n");
	printf("F5 = %d\n", ft_fibonacci(5));
	printf("-\n");
	printf("F6 = 8\n");
	printf("F6 = %d\n", ft_fibonacci(6));
	printf("-\n");
	printf("F7 = 13\n");
	printf("F7 = %d\n", ft_fibonacci(7));
	printf("-\n");
	printf("F8 = 21\n");
	printf("F8 = %d\n", ft_fibonacci(8));
	printf("-\n");
	printf("F9 = 34\n");
	printf("F9 = %d\n", ft_fibonacci(9));
	printf("-\n");
	printf("F10 = 55\n");
	printf("F10 = %d\n", ft_fibonacci(10));
}
*/