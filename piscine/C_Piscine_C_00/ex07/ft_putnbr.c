/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:23:15 by cpugnair          #+#    #+#             */
/*   Updated: 2022/08/03 11:35:46 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display(char *t, int num_digits, int is_negative)
{
	if (is_negative)
		write(1, "-", 1);
	while (num_digits >= 0)
	{
		ft_putchar('0' + t[num_digits]);
		num_digits--;
	}
}

void	ft_putnbr_display(int nb, char *c, int num_dig, int is_neg)
{
	while (nb != 0)
	{
		c[num_dig] = nb % 10;
		nb /= 10;
		num_dig++;
	}
	display(c, num_dig - 1, is_neg);
}

void	ft_putnbr(int nb)
{
	int		num_digits;
	int		is_negative;
	char	tab[11];

	num_digits = 0;
	is_negative = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		is_negative = 1;
		nb = -nb;
	}
	ft_putnbr_display(nb, tab, num_digits, is_negative);
}

/*
#include <stdio.h>

int	main(void)
{
	for (int i = -10; i < 20; i++)
	{
		printf(" <- Number %d", i);
		ft_putnbr(i);
		printf("\n");
	}
	printf(" <- Number %ld", -2147483648);
	ft_putnbr(-2147483648);
	printf("\n");
	printf(" <- Number %d", 2147483647);
	ft_putnbr(2147483647);
	printf("\n");
}
*/