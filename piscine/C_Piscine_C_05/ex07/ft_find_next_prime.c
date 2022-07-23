/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:01:25 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/23 06:47:44 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
int ft_is_prime(int nb)
{
	int i;
	int a;

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

int ft_find_next_prime(int nb)
{
	int	i;
	int	a;

	i = ft_is_prime(nb);
	a = 0;
	while (ft_is_prime(a))
	{
		if (ft_is_prime(i))
			return (i);
		i++;
	}
	return (0);
}

int	main(void)
{
	int	a = -1;

	for (int i = 0; i < 30; i++)
	{
		printf("Next prime of %d is %d\n", a, ft_find_next_prime(a));
		a++;
	}
}