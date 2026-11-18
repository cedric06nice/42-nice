/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:10:20 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/22 18:46:56 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H
# include "../includes/push_swap.h"
# include "../libft/includes/libft.h"
# include <limits.h>

void	load_in_stack_a(t_stack *stack,
						int x,
						int order,
						int flag,
						int keep);
void	load_in_stack_b(t_stack *stack,
						int x,
						int order,
						int flag,
						int keep);
t_stack	*load_test_values(void);
t_stack	*execute_push(int nb);

#endif
