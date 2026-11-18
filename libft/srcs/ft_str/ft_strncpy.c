/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:33:50 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/02 17:35:56 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	src_len;

	src_len = ft_strnlen(src, n);
	ft_memcpy(dest, src, src_len);
	dest[src_len] = '\0';
	return (dest);
}
