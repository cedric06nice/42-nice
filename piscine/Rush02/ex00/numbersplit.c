/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbersplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:21:59 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/07/30 17:02:49 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

unsigned int	intlen(unsigned int number)
{
	unsigned int	i;

	i = 0;
	while (number / 10 != 0)
	{
		number /= 10;
		i++;
	}
	i++;
	return (i);
}

unsigned int	**execute(unsigned int number, unsigned int **t)
{
	unsigned int	x;
	int				i;
	int				count;

	i = 2;
	x = 0;
	count = intlen(number);
	while (count > 0)
	{
		if (count > 2)
			t[x] = (unsigned int *) malloc(sizeof(unsigned int) * 3);
		else
			t[x] = (unsigned int *) malloc(sizeof(unsigned int) * count);
		while (i != -1)
		{
			t[x][i] = number % 10;
			number /= 10;
			count--;
			i--;
		}
		i = 2;
		x++;
	}
	t[x] = 0;
	return (t);
}

unsigned int	**numbersplit(unsigned int number)
{
	unsigned int	**t;

	if (!number || number < 1)
		return (0);
	t = (unsigned int **) malloc(sizeof(unsigned int *)
			* ((intlen(number) / 3) + 2));
	t = execute(number, t);
	return (t);
}
