/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:33:09 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/04 08:02:47 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void	print_u(t_flags *list, va_list ap)
{
	unsigned int	n;
	char			*num;

	n = va_arg(ap, unsigned int);
	if (n == 0)
		list->lenght += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		list->lenght += printstr(num);
		free(num);
	}
}

void	print_percent(t_flags *list, va_list ap)
{
	(void)ap;
	ft_putchar_fd('%', 1);
	list->lenght++;
}
