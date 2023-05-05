/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:29:39 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/05 09:15:08 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include "../libft/includes/libft.h"

typedef struct s_node
{
	int				x;
	int				order;
	int				flag;
	struct s_node	*next;
}					t_node;

typedef struct s_cmd
{
	char			*cmd;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_stack
{
	t_node			*list_a;
	t_node			*list_b;
	int				size;
	int				size_a;
	int				size_b;
	int				average;
	int				min;
	int				max;
	int				index;
	int				flag;
	t_cmd			*commands;
	int				error;
}					t_stack;

/* move_push */
void	pa(t_stack *stack);
void	pb(t_stack *stack);

/* move_rev_rotate */
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

/* move_rotate */
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);

/* move_swap */
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);

/* nodes_bubble_sort */
void	bubble_sort(t_stack *stack);

/* nodes_get_average */
int		get_mid_a(t_stack *stack);
int		get_mid_b(t_stack *stack);
void	set_average_values(t_stack *stack);
int		nodes_median_values(t_node *list);

/* nodes_get_max */
int		get_max_a(t_stack *stack);
int		get_max_b(t_stack *stack);
void	get_max_values(t_stack *stack, t_node *node, int size);

/* nodes_get_min */
int		get_min_a(t_stack *stack);
int		get_min_b(t_stack *stack);
void	get_min_values(t_stack *stack, t_node *node, int size);

/* nodes_insert */
void	nodes_insert_end(t_node **root, t_node *node);
void	nodes_insert_beginning(t_node **root, t_node *node);
void	nodes_insert_after(t_node *prev_node, int value, int order);
void	nodes_insert_command(t_stack **stack, char *command);

/* nodes_remove */
void	nodes_remove_first(t_node **root);
void	nodes_remove_last(t_node **root);
void	nodes_remove_element(t_node **root, int value);
void	nodes_delete(t_node **root);

/* nodes_utils */
int		nodes_count(t_node *root);
int		nodes_check_duplicate(t_node *root);
t_node	*nodes_get_nth_element(t_node *root, int index);
int		nodes_get_nth_value(t_node *root, int index);
int		get_nth_flag(t_node *root, int index);
int		nodes_has_loops(t_node *root);

/* program_init */
t_stack	*init(int argc, char **argv);

/* program_print */
void	print_commands(t_stack stack);
void	print_lists(t_stack stack, int extra);
void	print_linear(t_stack stack, int extra);
void	print_test(char *str);

/* program_sort_large_utils */
void	push_a(t_stack *all);
void	finish_sort(t_stack *all);
void	start_sort(t_stack *all, int i);
void	sort_large(t_stack *stack);

/* program_sort_large */
void	push_sort(t_stack *all);
int		extra_sorting(t_stack *all);
int		maxi_flag(t_node *stack, int size);

/* program_sort */
void	sort(t_stack *stack);

/* push_swap */
int		nodes_is_sorted(t_node **list, char c);
void	split_list(t_stack *stack);
void	merge_list(t_stack *stack);
void	reduce_commands(t_stack *stack);

#endif
