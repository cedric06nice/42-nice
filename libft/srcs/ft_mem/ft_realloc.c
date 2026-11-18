/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:58:31 by cpugnair          #+#    #+#             */
/*   Updated: 2026/11/18 18:00:00 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Reallocates a memory block of old_size bytes to new_size bytes.
**	- If new_size is 0, ptr is freed and NULL is returned.
**	- If ptr is NULL, behaves like malloc(new_size).
**	- Otherwise copies the lesser of old_size and new_size bytes to a new
**		block, frees ptr and returns the new block. On failure, ptr is left
**		untouched and NULL is returned.
**	Unlike realloc(3), the caller passes old_size: libft cannot read the
**	size of a malloc'd block, and copying new_size bytes would read past it.
*/
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (new_ptr == NULL || ptr == NULL)
		return (new_ptr);
	if (old_size < new_size)
		ft_memcpy(new_ptr, ptr, old_size);
	else
		ft_memcpy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}
