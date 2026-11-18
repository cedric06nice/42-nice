/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:32:14 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/24 19:09:42 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>

int		ft_is_number(char c);
int		ft_is_space(char c);
int		ft_atoi(int *tab, char str[]);
int		ft_tab_size(int tab[]);
int		ft_sqrt(int nb);
int		ft_strlen(char *str);
int		check_tab_values(int tab[], int max_size);
int		write_error(void);
void	ft_putchar(char c);
void	ft_print_tab(char **tab, int size);
int		check_add_up_value(int nb);
int		check_line(int side1, int tab[], int side2);
void	fill_line(int tab_head[], int nb_side, int *tab[]);

#endif
