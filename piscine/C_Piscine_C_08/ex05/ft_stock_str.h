/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 06:57:46 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/27 10:22:17 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stock_str {
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;

void	ft_putchar(char c);
void	display(char *t, int num_digits, int is_negative);
void	ft_putnbr_display(int nb, char *c, int num_dig, int is_neg);
void	ft_putnbr(int nb);
void	ft_show_tab(struct s_stock_str *par);

#endif