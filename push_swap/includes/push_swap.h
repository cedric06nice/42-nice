/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:29:39 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/17 00:06:38 by cpugnair         ###   ########.fr       */
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
	int				group;
	int				keep;
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
	int				min_a;
	int				max_a;
	int				size_b;
	int				min_b;
	int				max_b;
	int				average;
	int				min;
	int				max;
	int				index;
	int				group_min;
	int				group_max;
	int				flag;
	t_cmd			*commands;
	int				error;
}					t_stack;

/* bubble_sort */
void	bubble_sort(t_stack *stack);

/* commands_print */
void	print_commands(t_stack stack);

/* commands */
void	insert_command(t_stack **stack, char *command);
void	reduce_commands(t_stack *stack);

/* find_elements */
int		find_element_by_value(t_node *node, int value);
int		find_element_b_by_group(t_stack *stack, int group);
void	find_first_index_a(t_stack *stack);
int		find_position_to_insert_in_b(t_stack *stack, int val);
int		find_closest_group_in_b(t_stack *stack, int val);

/* get_max */
int		get_max_a(t_stack *stack);
int		get_max_b(t_stack *stack);
void	get_max_values(t_stack *stack, t_node *node, int size);
int		get_max_group_b(t_stack *stack);

/* get_min */
int		get_min_a(t_stack *stack);
int		get_min_b(t_stack *stack);
void	get_min_values(t_stack *stack, t_node *node, int size);
int		get_min_group_b(t_stack *stack);

/* init_stack */
void	init_stack(t_stack *stack);

/* move_p */
void	pa(t_stack *stack);
void	pb(t_stack *stack);

/* move_r */
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);

/* move_rr */
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

/* move_s */
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);

/* node_get */
t_node	*node_get_nth_elmt(t_node *root, int index);
int		node_get_nth_val(t_node *root, int index);
int		node_get_nth_flag(t_node *root, int index);
int		node_get_nth_group(t_node *root, int index);

/* node_insert */
void	node_insert_end(t_node **root, t_node *node);
void	node_insert_beg(t_node **root, t_node *node);
void	node_insert_aft(t_node *prev_node, int value, int order);

/* node_set_average */
void	set_average_values(t_stack *stack);

/* node_remove */
void	node_remove_fst(t_node **root);
void	node_remove_lst(t_node **root);
void	node_remove_elmt(t_node **root, int value);
void	node_delete(t_node **root);

/* node_sort */
int		node_is_sorted(t_node **list, char c);

/* node_utils */
int		node_count(t_node *root);
int		node_check_dup(t_node *root);
int		node_has_loops(t_node *root);

/* parse_load */
void	load_arguments(t_stack *stack, int	*list_num);

/* parse_transform */
int		*transform_args(char **arguments, int i, int count_args);

/* program_init */
t_stack	*init(int argc, char **argv);

/* program_sort_large_utils */
void	index_bottom_list_a(t_stack *stack);
void	sort_list_a(t_stack *stack);

/* push_shortest */
int		find_shortest_route_by_value(int min, t_node *node);
int		find_shortest_route_by_group(int group, t_node *node);
void	b_shortest_route_value(t_stack *stack, int value);
void	b_shortest_route_group(t_stack *stack, int group);
void	push_b_shortest(t_stack *stack);

/* sort_large */
void	sort_large(t_stack *stack);

/* sort */
void	sort(t_stack *stack);

/* split_merge */
void	split_list(t_stack *stack);
void	merge_list(t_stack *stack);

/* x_print_testing */
void	print_lists(t_stack stack, int extra);
void	print_linear(t_stack stack, int extra);
void	print_test(char *str);

/* OTHER */
int		nodes_get_nth_x_value(t_node *root, int index);
int		nodes_get_nth_order_value(t_node *root, int index);

#endif
