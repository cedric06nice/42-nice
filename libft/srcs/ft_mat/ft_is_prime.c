/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:31:49 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/16 20:16:49 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_is_prime function returns 1 if the number is prime, 0 otherwise
*/
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
