/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:31:49 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/21 10:27:05 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <math.h>
int	ft_is_prime(int nb)
{
	int	i;
	int	a;

	i = 2;
	a = 0;
	if (nb < 1)
		return (0);
	while (i <= nb / 2)
	{
		if (nb % i == 0)
			a++;
		i++;
	}
	if (a == 0 && nb != 1)
		return (nb);
	else
		return (0);
}
/*
int	main(void)
{
	int	a;

	a = -1;
	printf("ISPRIME %d = %d\n", a, ft_is_prime(a));
	printf("\n");
	a = 0;
	printf("ISPRIME %d = %d\n", a, ft_is_prime(a));
	printf("\n");
	a = 1;
	printf("ISPRIME %d = %d\n", a, ft_is_prime(a));
	printf("\n");
	a = 2;
	printf("ISPRIME %d = %d\n", a, ft_is_prime(a));
	printf("\n");
	a = 3;
	printf("ISPRIME %d = %d\n", a, ft_is_prime(a));
	printf("\n");
	a = 4;
	printf("ISPRIME %d = %d\n", a, ft_is_prime(a));
	printf("\n");
	a = 5;
	printf("ISPRIME %d = %d\n", a, ft_is_prime(a));
	printf("\n");
	a = 6;
	printf("ISPRIME %d = %d\n", a, ft_is_prime(a));
	printf("\n");
	a = 7;
	printf("ISPRIME %d = %d\n", a, ft_is_prime(a));
	printf("\n");
	a = 8;
	printf("ISPRIME %d = %d\n", a, ft_is_prime(a));
	printf("\n");
	a = 9;
	printf("ISPRIME %d = %d\n", a, ft_is_prime(a));
	printf("\n");
	a = 10;
	printf("ISPRIME %d = %d\n", a, ft_is_prime(a));
	printf("\n");
}
*/