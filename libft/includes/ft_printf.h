/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:46:52 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/04 07:56:41 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef struct s_flags
{
	char	flag;
	int		size;
	size_t	lenght;
}			t_flags;

int		ft_printf(const char *format, ...);
void	print_c(t_flags *list, va_list ap);
void	print_s(t_flags *list, va_list ap);
void	print_p(t_flags *list, va_list ap);
void	print_d(t_flags *list, va_list ap);
void	print_i(t_flags *list, va_list ap);
void	print_u(t_flags *list, va_list ap);
void	print_hex(t_flags *list, va_list ap, char flag);
void	print_percent(t_flags *list, va_list ap);

#endif
