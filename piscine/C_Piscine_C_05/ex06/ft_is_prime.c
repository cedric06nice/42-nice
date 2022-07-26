/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:31:49 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/25 12:38:30 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;
	int	a;

	i = 2;
	a = 0;
	if (nb == -2147483648)
		nb = 2147483647;
	if (nb == 0)
		return (0);
	if (nb < 0)
		nb = -nb;
	while (i <= nb / i)
	{
		if (nb % i == 0)
			a++;
		i++;
	}
	if (a == 0 && nb != 1)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <math.h>

int	main(void)
{
	int	a = -15;

	for (int i = 0; i < 30; i++)
	{
		printf("ISPRIME %d = %d\n", a, ft_is_prime(a));
		a++;
	}
	
	printf("ISPRIME %d = %d\n", 2147483647, ft_is_prime(2147483647));
	printf("ISPRIME %ld = %d\n", -2147483648, ft_is_prime(-2147483648));
}
*/