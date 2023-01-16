/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:06:04 by cpugnair          #+#    #+#             */
/*   Updated: 2022/11/19 23:04:09 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** The ft_calloc() function allocates memory for an array of nmemb elements
** of size bytes each and returns a pointer to the allocated memory.
** The memory is set to zero. If nmemb or size is 0, then calloc()
** returns either NULL, or a unique pointer value
** that can later be successfully passed to free().
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb > 65535 || size > 65535)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
