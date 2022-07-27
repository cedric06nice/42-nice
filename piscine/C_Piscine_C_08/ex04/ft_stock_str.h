/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 06:27:36 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/27 06:31:29 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_STR
# define FT_STOCK_STR

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

typedef struct s_stock_str {
	int size;
	char *str;
	char *copy;
}	t_stock_str

#endif