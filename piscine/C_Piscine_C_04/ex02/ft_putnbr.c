/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 08:57:57 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/22 08:24:40 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void display(char *t, int num_digits, int is_negative)
{
	if (is_negative)
		write(1, "-", 1);
	while (num_digits >= 0)
	{
		ft_putchar('0' + t[num_digits]);
		num_digits--;
	}
}

void ft_putnbr2(int nb, char *c, int num_digits, int is_negative)
{
	while (nb != 0)
	{
		c[num_digits] = nb % 10;
		nb /= 10;
		num_digits++;
	}
	display(c, num_digits - 1, is_negative);
}

void ft_putnbr(int nb)
{
	int num_digits;
	int is_negative;
	char tab[20];

	num_digits = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return;
	}
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return;
	}
	if (nb < 0)
	{
		is_negative = 1;
		nb = -nb;
	}
	else
		is_negative = 0;
	while (nb != 0)
	{
		tab[num_digits] = nb % 10;
		nb /= 10;
		num_digits++;
	}
	display(tab, num_digits - 1, is_negative);
}
/*
int main(void)
{
	for (int i = -10; i < 20; i++)
	{
		printf(" <- Number %d", i);
		ft_putnbr(i);
		printf("\n");
	}
}
*/