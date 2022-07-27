/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:37:04 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/27 13:27:07 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"
# define SUCCESS 0
# define EVEN(x) x % 2 == 0

# include <unistd.h>

typedef enum e_bool {
	FALSE = 0,
	TRUE = 1
}	t_bool;

void	ft_putstr(char *str);
t_bool	ft_is_even(int nbr);
int		main(int argc, char **argv);
#endif