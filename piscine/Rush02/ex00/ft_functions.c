/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:31:13 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/31 17:32:47 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_str_len(char *str)
{
	int	i;

	i = 1;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_int_len(unsigned int number)
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

int	ft_pow(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power != 0)
		return (nb * ft_pow(nb, power - 1));
	else
		return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
	{
		if (s1[i] == 0 || s2[i] == 0)
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}
