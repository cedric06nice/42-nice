/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:02:54 by cpugnair          #+#    #+#             */
/*   Updated: 2022/08/04 17:21:15 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOP_H
# define DOOP_H
# include <unistd.h>
# include <stdio.h>

int		ft_atoi(char *str);
int		ft_is_number(char c);
int		ft_is_space(char c);
int		ft_is_sign(char c);
int		ft_is_minus(char c);

int		ft_add(int a, int b);
int		ft_sub(int a, int b);
int		ft_mul(int a, int b);
int		ft_div(int a, int b);
int		ft_mod(int a, int b);

void	ft_putnbr(int nb);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	display(char *t, int num_digits, int is_negative);
void	ft_putnbr_display(int nb, char *c, int num_dig, int is_neg);

int		ft_strcmp(char *s1, char *s2);

#endif