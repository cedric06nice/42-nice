/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:01:25 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/25 14:16:32 by cpugnair         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 0;
	if (nb < 2)
		return (2);
	while (!ft_is_prime(nb + i))
		i++;
	return (i + nb);
}
/*
#include <stdio.h>
#include <math.h>

int	main(void)
{
	int	a = -15;

	for (int i = 0; i < 30; i++)
	{
		printf("Next prime of %d is %d\n", a, ft_find_next_prime(a));
		a++;
	}
}
*/