/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:20:24 by cpugnair          #+#    #+#             */
/*   Updated: 2022/08/04 16:10:03 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

int	ft_is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_is_minus(char c)
{
	if (c == '-')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	count_minus;
	int	number;

	i = 0;
	count_minus = 0;
	number = 0;
	while (ft_is_space(str[i]))
		i++;
	while (ft_is_sign(str[i]))
	{
		count_minus += ft_is_minus(str[i]);
		i++;
	}
	while (ft_is_number(str[i]))
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	if (count_minus % 2 == 1)
		number *= -1;
	return (number);
}
