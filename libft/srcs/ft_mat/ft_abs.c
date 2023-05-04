/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:28:56 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/16 20:29:17 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_abs function returns the absolute value of the number
*/
int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
