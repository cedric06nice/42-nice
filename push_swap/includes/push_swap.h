/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:29:39 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/04 16:18:53 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <limits.h>

typedef struct s_node
{
	int				x;
	int				order;
	int				flag;
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
	int				flag;
	t_cmd			*commands;
	int				error;
}					t_stack;

/* atoi */
int					*ps_atoi(char *str);

/* cmds_add */
void				add_command(t_stack **stack, char *command);

/* cmds_empty */
void				empty_commands(t_cmd **root);

/* cmds_print */
void				print_commands(t_stack stack);

/* cmds_reduce */
void				reduce_commands(t_stack *stack);

/* find_a */
int					order_to_insert_in_a(t_stack *stack, int order);
int					find_where_to_insert_in_a(t_stack *stack, int order);
int					find_best_move(t_stack *stack);

/* find_best_greater_than */
int					find_best_suite_by_greater_than(t_stack *stack);
void				set_best_suite_by_greater_than(t_stack *stack);

/* find_best_index */
void				reset_keep(t_stack *stack);
int					find_best_suite_by_index(t_stack *stack);
void				set_best_suite_by_index(t_stack *stack);

/* find_elements */
int					find_element_by_value(t_node *node, int value);

/* get_max */
int					get_max_a(t_stack *stack);
int					get_max_b(t_stack *stack);
void				get_max_values(t_stack *stack, t_node *node, int size);

/* get_min */
int					get_min_a(t_stack *stack);
int					get_min_b(t_stack *stack);
void				get_min_values(t_stack *stack, t_node *node, int size);

/* init_stack */
void				init_stack(t_stack *stack);

/* move_p */
void				pa(t_stack *stack);
void				pb(t_stack *stack);

/* move_r */
void				ra(t_stack *stack);
void				rb(t_stack *stack);
void				rr(t_stack *stack);

/* move_rr */
void				rra(t_stack *stack);
void				rrb(t_stack *stack);
void				rrr(t_stack *stack);

/* move_s */
void				sa(t_stack *stack);
void				sb(t_stack *stack);
void				ss(t_stack *stack);

/* node_get */
t_node				*node_get_nth_elmt(t_node *root, int index);
int					node_get_nth_val(t_node *root, int index);
int					node_get_nth_flag(t_node *root, int index);
int					node_get_index_for_order(t_node *root, int order);

/* node_insert */
void				node_insert_end(t_node **root, t_node *node);
void				node_insert_beg(t_node **root, t_node *node);
void				node_insert_aft(t_node *prev_node, int value, int order);

/* node_remove */
void				node_remove_fst(t_node **root);
void				node_remove_lst(t_node **root);
void				node_remove_elmt(t_node **root, int value);
void				node_delete(t_node **root);

/* node_set_average */
void				set_average_values(t_stack *stack);

/* node_sort */
int					node_is_sorted(t_node **list, char c);

/* node_utils */
int					node_count(t_node *root);
int					node_check_dup(t_node *root);

/* parse_load */
void				add_node(t_stack *stack, int *list_num, int i, int idx_num);
void				load_arguments(t_stack *stack, int *list_num);

/* parse_token */
void				free_tokens(char **tokens, int num_count);
char				**tokenize_string(const char *input_string,	int *num_count);

/* parse_transform */
int					*string_to_number(const char *input_str, int *num_count);
int					*numbers_to_number(int argc, char **argv, int *num_count);

/* program_end */
void				end_program(char *str);

/* program_init */
void				init(t_stack *stack, int argc, char **argv);

/* push_shortest */
int					find_shortest_route_by_value(int min, t_node *node);

/* sort_large */
int					only_keeps(t_stack *stack);
void				push_b_in_best_a(t_stack *stack);
void				sort_large(t_stack *stack);

/* sort */
void				sort(t_stack *stack);

/* x_print_testing */
// void		print_lists(t_stack stack, int extra);
// void		print_linear(t_stack stack, int extra);
// void		print_test(char *str);

#endif
