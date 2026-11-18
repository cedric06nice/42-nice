/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:06:14 by cpugnair          #+#    #+#             */
/*   Updated: 2022/11/19 23:03:16 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** The ft_isascii() checks whether c is a 7-bit unsigned char
** value that fits into the ASCII character set.
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
