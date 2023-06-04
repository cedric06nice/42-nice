/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:16:59 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/04 16:05:40 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Remove first element of the list
*/
void	node_remove_fst(t_node **root)
{
	t_node	*tmp;

	if (*root == NULL)
		return ;
	tmp = *root;
	*root = (*root)->next;
	free(tmp);
}

/*
** Remove last element of the list
*/
void	node_remove_lst(t_node **root)
{
	t_node	*tmp;
	t_node	*prev;

	if (*root == NULL)
		return ;
	tmp = *root;
	if (tmp->next == NULL)
	{
		free(tmp);
		*root = NULL;
		return ;
	}
	while (tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	free(tmp);
}

/*
** Remove element with specific value
*/
void	node_remove_elmt(t_node **root, int value)
{
	t_node	*tmp;
	t_node	*prev;

	if (*root == NULL)
		return ;
	if ((*root)->x == value)
	{
		tmp = *root;
		*root = (*root)->next;
		free(tmp);
		return ;
	}
	tmp = *root;
	while (tmp != NULL && tmp->x != value)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return ;
	prev->next = tmp->next;
	free(tmp);
}

/*
** Delete all nodes
*/
void	node_delete(t_node **root)
{
	t_node	*tmp;
	t_node	*prev;

	tmp = *root;
	while (tmp != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
		free(prev);
		*root = NULL;
	}
}
