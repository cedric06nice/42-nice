/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:50:11 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/16 21:23:02 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_pow function returns the power of a number
*/
int	ft_pow(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power != 0)
		return (nb * ft_pow(nb, power - 1));
	else
		return (1);
}
