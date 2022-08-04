/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:17:46 by cpugnair          #+#    #+#             */
/*   Updated: 2022/08/04 17:19:11 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

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
