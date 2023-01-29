/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:47:05 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/29 11:44:37 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_flags(va_list args, const char flag);
static void	ft_print_c(t_flags *list, va_list ap);
static void	ft_print_s(t_flags *list, va_list ap);
static void	ft_print_p(t_flags *list, va_list ap);
static void	ft_print_d(t_flags *list, va_list ap);
static void	ft_print_i(t_flags *list, va_list ap);
static void	ft_print_u(t_flags *list, va_list ap);
static void	ft_print_hex(t_flags *list, va_list ap, char flag);
static void	ft_print_percent(t_flags *list, va_list ap);

/*
** %c Affiche un seul caractère.
** %s Affiche une chaîne de caractères
** %p L’argument de pointeur void * doit être affiché en hexadécimal.
** %d Affiche un nombre décimal (base 10).
** %i Affiche un entier en base 10.
** %u Affiche un nombre décimal non signé (base 10).
** %x Affiche un nombre en hexadécimal (base 16) avec des lettres minuscules.
** %X Affiche un nombre en hexadécimal (base 16) avec des lettres majuscules.
** %% Affiche un signe pourcentage.
*/
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, 1);
			len++;
		}
		else
		{
			format++;
			len += ft_flags(args, *format);
		}
		format++;
	}
	va_end(args);
	return (len);
}

static int	ft_flags(va_list args, const char flag)
{
	t_flags	list;

	list.flag = flag;
	list.lenght = 0;
	if (flag == 'c')
		ft_print_c(&list, args);
	else if (flag == 's')
		ft_print_s(&list, args);
	else if (flag == 'p')
		ft_print_p(&list, args);
	else if (flag == 'd')
		ft_print_d(&list, args);
	else if (flag == 'i')
		ft_print_i(&list, args);
	else if (flag == 'u')
		ft_print_u(&list, args);
	else if (flag == 'x' || flag == 'X')
		ft_print_hex(&list, args, flag);
	else if (flag == '%')
		ft_print_percent(&list, args);
	return (list.lenght);
}

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

static int	ft_hex_len(unsigned	int num)
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

static void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

static void	ft_print_hex(t_flags *list, va_list ap, char flag)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		list->lenght++;
		return ;
	}
	else
	{
		ft_put_hex(n, flag);
		list->lenght += ft_hex_len(n);
	}
}

static void	ft_print_c(t_flags *list, va_list ap)
{
	ft_putchar_fd(va_arg(ap, int), 1);
	list->lenght++;
}

static void	ft_print_s(t_flags *list, va_list ap)
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

static void	ft_print_d(t_flags *list, va_list ap)
{
	char	*str;

	str = ft_itoa(va_arg(ap, int));
	ft_putstr_fd(str, 1);
	list->lenght += ft_strlen(str);
	free(str);
}

static void	ft_print_i(t_flags *list, va_list ap)
{
	char	*str;

	str = ft_itoa(va_arg(ap, int));
	ft_putstr_fd(str, 1);
	list->lenght += ft_strlen(str);
	free(str);
}

static int	ft_ptr_len(uintptr_t num)
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

static void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

static void	ft_print_p(t_flags *list, va_list ap)
{
	uintptr_t	ptr;

	ptr = va_arg(ap, unsigned long long);
	list->lenght += write(1, "0x", 2);
	if (ptr == 0)
		list->lenght += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		list->lenght += ft_ptr_len(ptr);
	}
}

static void	ft_print_u(t_flags *list, va_list ap)
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

static void	ft_print_percent(t_flags *list, va_list ap)
{
	(void)ap;
	ft_putchar_fd('%', 1);
	list->lenght++;
}
