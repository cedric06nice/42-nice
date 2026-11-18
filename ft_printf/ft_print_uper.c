/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:33:09 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/03 11:10:21 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printstr(char *str)
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

static int	ft_num_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

void	ft_print_u(t_flags *list, va_list ap)
{
	unsigned int	n;
	char			*num;

	n = va_arg(ap, unsigned int);
	if (n == 0)
		list->lenght += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		list->lenght += ft_printstr(num);
		free(num);
	}
}

void	ft_print_percent(t_flags *list, va_list ap)
{
	(void)ap;
	ft_putchar_fd('%', 1);
	list->lenght++;
}
