/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:06:14 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/16 19:32:21 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_isascii() checks whether c is a 7-bit unsigned char
** value that fits into the ASCII character set.
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
