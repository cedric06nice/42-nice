/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:00:33 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/04 08:03:02 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		put_ptr(num / 16);
		put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

void	print_p(t_flags *list, va_list ap)
{
	uintptr_t	ptr;

	ptr = va_arg(ap, unsigned long long);
	list->lenght += write(1, "0x", 2);
	if (ptr == 0)
		list->lenght += write(1, "0", 1);
	else
	{
		put_ptr(ptr);
		list->lenght += ptr_len(ptr);
	}
}
