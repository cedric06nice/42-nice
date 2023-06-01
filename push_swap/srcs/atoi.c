/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 02:30:37 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/25 16:06:10 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\f' || c == '\v');
}

static int	is_overflow(int sign, int result, int digit)
{
	if (sign == 1)
	{
		if (result > INT_MAX / 10
			|| (result == INT_MAX / 10 && digit > INT_MAX % 10))
			return (1);
	}
	else
	{
		if (result < INT_MIN / 10
			|| (result == INT_MIN / 10 && digit > -(INT_MIN % 10)))
			return (1);
	}
	return (0);
}

static int	part2(int result, int digit, int sign)
{
	if (is_overflow(sign, result, digit))
	{
		if (sign == 1)
			return (INT_MAX);
		return (INT_MIN);
	}
	result = (result * 10) + (sign * digit);
	return (result);
}

int	ps_atoi(const char *str)
{
	int	sign;
	int	i;
	int	result;
	int	digit;

	sign = 1;
	i = 0;
	result = 0;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		digit = str[i] - '0';
		result = part2(result, digit, sign);
		i++;
	}
	return (result);
}
