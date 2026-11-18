/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:58:52 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/03 09:59:38 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int		a;
	int		b;

	a = printf("A char (c) %c\n", 'Z');
	printf("%d\n", a);
	b = ft_printf("A char (c) %c\n", 'Z');
	printf("%d\n", b);

	printf("\n");
	a = printf("A string (s) %s\n", "str");
	printf("%d\n", a);
	b = ft_printf("A string (s) %s\n", "str");
	printf("%d\n", b);

	printf("\n");
	a = printf("A pointer (p) %p\n", &a);
	printf("%d\n", a);
	b = ft_printf("A pointer (p) %p\n", &a);
	printf("%d\n", b);

	printf("\n");
	a = printf("A decimal (d) %d / %d\n", 424242, -424242);
	printf("%d\n", a);
	b = ft_printf("A decimal (d) %d / %d\n", 424242, -424242);
	printf("%d\n", b);

	printf("\n");
	a = printf("An integer (i) %i / %i\n", 424242, -424242);
	printf("%d\n", a);
	b = ft_printf("An integer (i) %i / %i\n", 424242, -424242);
	printf("%d\n", b);

	printf("\n");
	a = printf("An unsigned integer (u) %u / %u\n", 42, -42);
	printf("%d\n", a);
	b = ft_printf("An unsigned integer (u) %u / %u\n", 42, -42);
	printf("%d\n", b);

	printf("\n");
	a = printf("An unsigned integer (u) with 0 : %u\n", 0);
	printf("%d\n", a);
	b = ft_printf("An unsigned integer (u) with 0 : %u\n", 0);
	printf("%d\n", b);

	printf("\n");
	a = printf("An unsigned integer (u) with INT_MIN : %u\n", INT_MIN);
	printf("%d\n", a);
	b = ft_printf("An unsigned integer (u) with INT_MIN : %u\n", INT_MIN);
	printf("%d\n", b);

	printf("\n");
	a = printf("An unsigned integer (u) with LONG_MAX : %ld\n", LONG_MAX);
	printf("%d\n", a);
	b = ft_printf("An unsigned integer (u) with LONG_MAX : %u\n", LONG_MAX);
	printf("%d\n", b);

	printf("\n");
	a = printf("An unsigned integer (u) with LONG_MIN : %ld\n", LONG_MIN);
	printf("%d\n", a);
	b = ft_printf("An unsigned integer (u) with LONG_MIN : %u\n", LONG_MIN);
	printf("%d\n", b);

	printf("\n");
	a = printf("An unsigned integer (u) with ULONG_MAX : %ld\n", ULONG_MAX);
	printf("%d\n", a);
	b = ft_printf("An unsigned integer (u) with ULONG_MAX : %u\n", ULONG_MAX);
	printf("%d\n", b);

	printf("\n");
	a = printf("An unsigned integer (u) with 9223372036854775807LL : %lld\n", 9223372036854775807LL);
	printf("%d\n", a);
	b = ft_printf("An unsigned integer (u) with 9223372036854775807LL : %u\n", 9223372036854775807LL);
	printf("%d\n", b);

	printf("\n");
	a = printf("An unsigned integer (u) with mix tests : %u %u %ld %ld %lu %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("%d\n", a);
	b = ft_printf("An unsigned integer (u) with mix tests : %u %u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("%d\n", b);

	printf("\n");
	a = printf("A lowercased hexadecimal (x) %x\n", 424242);
	printf("%d\n", a);
	b = ft_printf("A lowercased hexadecimal (x) %x\n", 424242);
	printf("%d\n", b);

	printf("\n");
	a = printf("An uppercased hexadecimal (X) %X\n", -424242);
	printf("%d\n", a);
	b = ft_printf("An uppercased hexadecimal (X) %X\n", -424242);
	printf("%d\n", b);

	printf("\n");
	a = printf("A percent sign %%\n");
	printf("%d\n", a);
	b = ft_printf("A percent sign %%\n");
	printf("%d\n", b);

	printf("\n");
	a = printf("Test arm64 %c, %s, %p, %d, %i, %u, %x, %X, %%\n",
			'Z', "str", &a, 42, -42, -42, 123456789, -123456789);
	printf("%d\n", a);
	b = ft_printf("Test arm64 %c, %s, %p, %d, %i, %u, %x, %X, %%\n",
			'Z', "str", &a, 42, -42, -42, 123456789, -123456789);
	printf("%d\n", b);

	printf("\n");
	a = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A',
"42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("%d\n", a);
	b = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A',
"42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("%d\n", b);

	return (0);
}
