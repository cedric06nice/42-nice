/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 06:55:44 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/27 17:22:25 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

void	check(int *nb)
{
	if (*nb < 0)
	{
		ft_putchar('-');
		if (*nb == -2147483648)
		{
			ft_putchar('2');
			*nb = 147483648;
		}
		else
			*nb = -*nb;
	}
}

void	ft_putnbr(int nb)
{
	int	size;
	int	temp;

	size = 1;
	check(&nb);
	temp = nb / 10;
	while (temp > 0)
	{
		temp /= 10;
		size *= 10;
	}
	temp = nb;
	while (size > 0)
	{
		ft_putchar((temp / size) + '0');
		temp = temp % size;
		size /= 10;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putstr("\n");
		ft_putnbr(par[i].size);
		ft_putstr("\n");
		ft_putstr(par[i].copy);
		ft_putstr("\n");
		i++;
	}	
}
