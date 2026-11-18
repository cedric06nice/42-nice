/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:58:31 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/02 16:59:39 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Reallocates a memory block.
**	- If size is 0, the memory block pointed to by ptr is freed.
**	- If ptr is NULL, the function behaves like malloc().
**	- Otherwise, the function behaves like malloc() with the following
**		differences:
**		- The contents of the memory block are copied to the new memory block,
**			up to the lesser of the new and old sizes.
**		- If the new size is larger than the old size, the added memory is not
**			initialized.
**		- If ptr is not NULL, it must have been returned by a previous call to
**			malloc(), calloc() or realloc(). Otherwise, or if the memory block
**			has been freed with free() or realloc(), the behavior is undefined.
*/
void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (ptr == NULL)
		return (malloc(size));
	else
	{
		new_ptr = malloc(size);
		if (new_ptr != NULL)
		{
			ft_memcpy(new_ptr, ptr, size);
			free(ptr);
		}
		return (new_ptr);
	}
}
