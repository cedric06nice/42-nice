/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:53:05 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/16 20:15:41 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_sqrt function returns the square root of a number
*/
int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i < 46341 && i * i < nb)
		i++;
	if (i * i != nb)
		return (0);
	return (i);
}
