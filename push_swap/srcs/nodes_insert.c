/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:02:13 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/12 09:11:57 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Insert a node at the end of the list (root)
*/
void	nodes_insert_end(t_node **root, t_node *node)
{
	t_node	*new_node;
	t_node	*curr;

	if (*root == NULL)
	{
		*root = malloc(sizeof(t_node));
		if (*root == NULL)
			return ;
		(*root)->x = node->x;
		(*root)->order = node->order;
		(*root)->flag = node->flag;
		(*root)->group = node->group;
		(*root)->next = NULL;
		return ;
	}
	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->x = node->x;
	new_node->order = node->order;
	new_node->flag = node->flag;
	new_node->group = node->group;
	new_node->next = NULL;
	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

/*
** Insert a node at the beginning of the list (root)
*/
void	nodes_insert_beginning(t_node **root, t_node *node)
{
	t_node	*tmp;

	if (node == NULL)
		return ;
	if (*root == NULL)
	{
		*root = malloc(sizeof(t_node));
		if (*root == NULL)
			return ;
		(*root)->x = node->x;
		(*root)->order = node->order;
		(*root)->flag = node->flag;
		(*root)->group = node->group;
		(*root)->next = NULL;
		return ;
	}
	else
	{
		tmp = malloc(sizeof(t_node));
		tmp->x = node->x;
		tmp->order = node->order;
		tmp->flag = node->flag;
		tmp->group = node->group;
		tmp->next = *root;
		*root = tmp;
	}
}

/*
** Insert a node after the node with value and order
*/
void	nodes_insert_after(t_node *node, int value, int order)
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

/*
** Insert the command at the end of the list
*/
void	nodes_insert_command(t_stack **stack, char *command)
{
	t_cmd	*root;
	t_cmd	*new_cmd;
	t_cmd	*curr;

	if (stack == NULL || command == NULL)
		return ;
	if (ft_strcmp(command, "pa") != 0 && ft_strcmp(command, "pb") != 0
		&& ft_strcmp(command, "rra") != 0 && ft_strcmp(command, "rrb") != 0 && ft_strcmp(command, "rrr") != 0
		&& ft_strcmp(command, "ra") != 0 && ft_strcmp(command, "rb") != 0 && ft_strcmp(command, "rr") != 0
		&& ft_strcmp(command, "sa") != 0 && ft_strcmp(command, "sb") != 0 && ft_strcmp(command, "ss") != 0)
		return ;
	root = (*stack)->commands;
	if ((*stack)->commands == NULL)
	{
		(*stack)->commands = malloc(sizeof(t_cmd));
		if ((*stack)->commands == NULL)
			exit (1);
		(*stack)->commands->cmd = command;
		(*stack)->commands->next = NULL;
		return ;
	}
	new_cmd = malloc(sizeof(t_cmd));
	if (new_cmd == NULL)
		exit (1);
	new_cmd->cmd = command;
	new_cmd->next = NULL;
	curr = root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_cmd;
}
