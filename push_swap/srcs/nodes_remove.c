/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:16:59 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/09 22:22:10 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nodes_remove_first(t_node **root)
{
	t_node	*tmp;

	if (*root == NULL)
		return ;
	tmp = *root;
	*root = (*root)->next;
	free(tmp);
}

void	nodes_remove_last(t_node **root)
{
	t_node	*tmp;
	t_node	*prev;

	if (*root == NULL)
		return ;
	tmp = *root;
	while (tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	free(tmp);
}

void	nodes_remove_element(t_node **root, int value)
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
	while (tmp->x != value)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = tmp->next;
	free(tmp);
}

void	nodes_delete(t_node **root)
{
	t_node	*tmp;
	t_node	*prev;

	tmp = *root;
	while (tmp != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
		free(prev);
	}
	*root = NULL;
}
