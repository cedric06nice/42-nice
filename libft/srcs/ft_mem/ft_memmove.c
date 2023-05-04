/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:07:20 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/16 19:33:10 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_memmove() function copies n bytes from memory area src
** to memory area dest. The memory areas may overlap:
** copying takes place as though the bytes in src
** are first copied into a temporary array that does not overlap src or dest,
** and the bytes are then copied from the temporary array to dest.
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cdest;
	const char	*csrc;

	cdest = (char *)dst;
	csrc = (const char *)src;
	if (!len)
		return (cdest);
	if (!dst && !src)
		return (0);
	if (cdest <= csrc)
		return (ft_memcpy(dst, src, len));
	cdest += len;
	csrc += len;
	while (len--)
		*--cdest = *--csrc;
	return (dst);
}
