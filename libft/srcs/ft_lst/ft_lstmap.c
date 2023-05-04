/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:25:39 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/04 08:00:18 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*lstnewdel(void *content, void (*del)(void *));

/*
** The function ft_lstmap() applies the function f to the content of each
** element of the list lst and creates a new list resulting from the
** successive applications of f. The del function is used to delete the
** content of an element if necessary.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	new = lstnewdel(f(lst->content), del);
	if (!new)
		return (NULL);
	lst = lst->next;
	tmp = new;
	while (lst)
	{
		new->next = lstnewdel(f(lst->content), del);
		if (!new->next)
		{
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (tmp);
}

static t_list	*lstnewdel(void *content, void (*del)(void *))
{
	t_list	*new;

	new = ft_lstnew(content);
	if (!new)
		del(content);
	return (new);
}
