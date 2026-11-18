/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:07:56 by cpugnair          #+#    #+#             */
/*   Updated: 2022/11/19 23:05:09 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** The ft_strlcat() function appends the NUL-terminated string
** src to the end of dst. It will append at most size - strlen(dst) - 1 bytes,
** NUL-terminating the result.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[j] && j < size)
		j++;
	while (src[i] && size && j + i < size - 1)
	{
		dst[j + i] = src[i];
		i++;
	}
	if (j < size)
		dst[j + i] = 0;
	i = 0;
	while (src[i])
		i++;
	return (j + i);
}
