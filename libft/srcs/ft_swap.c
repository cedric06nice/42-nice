/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:55:28 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/16 21:39:47 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_swap() function swaps the values of two variables
** of the same type and size of the variable
** passed as a parameter to the function
*/
void	ft_swap(void *a, void *b, size_t size)
{
	char	*tmp;

	tmp = malloc(size);
	ft_memcpy(tmp, a, size);
	ft_memcpy(a, b, size);
	ft_memcpy(b, tmp, size);
	free(tmp);
}
