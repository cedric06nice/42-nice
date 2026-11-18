/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:19:01 by cpugnair          #+#    #+#             */
/*   Updated: 2022/11/19 23:03:37 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** The ft_lstclear() function takes as a parameter the address of a pointer
** to a link and frees the memory of this link and all the successors of
** this link using the functions del and free.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*next;

	if (!lst || !del)
		return ;
	ptr = lst[0];
	lst[0] = NULL;
	while (ptr)
	{
		next = ptr->next;
		del(ptr->content);
		free(ptr);
		ptr = next;
	}
}
