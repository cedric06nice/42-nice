/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:02:13 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/23 00:37:49 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_node(t_node **new_node, t_node *node)
{
	(*new_node)->x = node->x;
	(*new_node)->order = node->order;
	(*new_node)->flag = node->flag;
	(*new_node)->keep = node->keep;
	(*new_node)->next = NULL;
}

/*
** Insert a node at the end of the list (root)
*/
void	node_insert_end(t_node **root, t_node *node)
{
	t_node	*new_node;
	t_node	*curr;

	new_node = NULL;
	curr = NULL;
	if (*root == NULL)
	{
		*root = malloc(sizeof(t_node));
		if (*root == NULL)
			return ;
		set_node(&(*root), node);
		return ;
	}
	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	set_node(&new_node, node);
	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

/*
** Insert a node at the beginning of the list (root)
*/
void	node_insert_beg(t_node **root, t_node *node)
{
	t_node	*tmp;

	tmp = NULL;
	if (node == NULL)
		return ;
	if (*root == NULL)
	{
		*root = malloc(sizeof(t_node));
		if (*root == NULL)
			return ;
		set_node(&(*root), node);
		return ;
	}
	else
	{
		tmp = malloc(sizeof(t_node));
		if (tmp == NULL)
			return ;
		tmp->x = node->x;
		tmp->order = node->order;
		tmp->flag = node->flag;
		tmp->next = *root;
		*root = tmp;
	}
}

/*
** Insert a node after the node with value and order
*/
void	node_insert_aft(t_node *node, int value, int order)
{
	t_node	*new_node;

	if (node == NULL)
		return ;
	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		exit (1);
	new_node->x = value;
	new_node->order = order;
	new_node->next = node->next;
	node->next = new_node;
}
