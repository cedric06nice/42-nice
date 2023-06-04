/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 02:30:37 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/03 21:36:21 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f'
		|| c == '\v');
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

static int	*loop_atoi(char *str, int *sign, int *result)
{
	int	i;
	int	digit;

	i = 0;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	if (!is_digit(str[i]))
		return (NULL);
	while (str[i])
	{
		digit = str[i] - '0';
		if (is_overflow(*sign, *result, digit) || !is_digit(str[i]))
			return (NULL);
		*result = (*result * 10) + (*sign * digit);
		i++;
	}
	return (result);
}

int	*ps_atoi(char *str)
{
	int	sign;
	int	result;
	int	*final_result;
	int	*res;

	sign = 1;
	result = 0;
	res = loop_atoi(str, &sign, &result);
	if (res == NULL)
		return (NULL);
	final_result = malloc(sizeof(int));
	if (final_result == NULL)
		return (NULL);
	*final_result = result;
	return (final_result);
}
