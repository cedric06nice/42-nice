/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:47:05 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/04 07:56:22 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flags(va_list args, const char flag);

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
			len += flags(args, *format);
		}
		format++;
	}
	va_end(args);
	return (len);
}

static int	flags(va_list args, const char flag)
{
	t_flags	list;

	list.flag = flag;
	list.lenght = 0;
	if (flag == 'c')
		print_c(&list, args);
	else if (flag == 's')
		print_s(&list, args);
	else if (flag == 'p')
		print_p(&list, args);
	else if (flag == 'd')
		print_d(&list, args);
	else if (flag == 'i')
		print_i(&list, args);
	else if (flag == 'u')
		print_u(&list, args);
	else if (flag == 'x' || flag == 'X')
		print_hex(&list, args, flag);
	else if (flag == '%')
		print_percent(&list, args);
	return (list.lenght);
}
