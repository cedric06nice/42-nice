/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:31:49 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/25 08:30:41 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;
	int	a;

	i = 2;
	a = 0;
	while (i <= nb / i)
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
#include <stdio.h>
#include <math.h>

int	main(void)
{
	int	a = -20;

	for (int i = 0; i < 60; i++)
	{
		printf("ISPRIME %d = %d\n", a, ft_is_prime(a));
		a++;
	}
}
*/