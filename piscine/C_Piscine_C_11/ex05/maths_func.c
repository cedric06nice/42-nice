/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:32:04 by cpugnair          #+#    #+#             */
/*   Updated: 2022/08/04 17:07:08 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

int	ft_add(int a, int b)
{
	return (a + b);
}

int	ft_sub(int a, int b)
{
	return (a - b);
}

int	ft_mul(int a, int b)
{
	return (a * b);
}

int	ft_div(int a, int b)
{
	if (b)
		return (a / b);
	else
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
}

int	ft_mod(int a, int b)
{
	if (b)
		return (a % b);
	else
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
}
