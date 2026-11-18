/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:46:52 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/03 11:06:19 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include "libft/includes/libft.h"

typedef struct s_flags
{
	char	flag;
	int		size;
	size_t	lenght;
}				t_flags;

int		ft_printf(const char *format, ...);
void	ft_print_c(t_flags *list, va_list ap);
void	ft_print_s(t_flags *list, va_list ap);
void	ft_print_p(t_flags *list, va_list ap);
void	ft_print_d(t_flags *list, va_list ap);
void	ft_print_i(t_flags *list, va_list ap);
void	ft_print_u(t_flags *list, va_list ap);
void	ft_print_hex(t_flags *list, va_list ap, char flag);
void	ft_print_percent(t_flags *list, va_list ap);

#endif
