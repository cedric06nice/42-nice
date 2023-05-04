/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csdi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:47:05 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/04 08:02:33 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(t_flags *list, va_list ap)
{
	ft_putchar_fd(va_arg(ap, int), 1);
	list->lenght++;
}

void	print_s(t_flags *list, va_list ap)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
		list->lenght++;
	}
}

void	print_d(t_flags *list, va_list ap)
{
	char	*str;

	str = ft_itoa(va_arg(ap, int));
	ft_putstr_fd(str, 1);
	list->lenght += ft_strlen(str);
	free(str);
}

void	print_i(t_flags *list, va_list ap)
{
	char	*str;

	str = ft_itoa(va_arg(ap, int));
	ft_putstr_fd(str, 1);
	list->lenght += ft_strlen(str);
	free(str);
}
