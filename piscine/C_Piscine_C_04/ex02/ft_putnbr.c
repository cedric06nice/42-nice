/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 08:57:57 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/20 16:30:27 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	pow(int n)
{
	int	pow;

	pow = 0;
	if (n >= 1)
	{
		pow = 1;
		n--;
	}
	while (n != 0)
	{
		pow *= 10;
		n--;
	}
	return (pow);
}

void	verif0(int nb)
{
	if (nb == 0)
		write(1, "0", 1);
}

void	calcul_response(int nb, int x)
{
	char	rep;
	int		res;

	while (x > 0)
	{
		res = nb / pow(x);
		nb = nb - (res * pow(x));
		rep = '0' + res;
		if (res != 0)
			write(1, &rep, 1);
		verif0(res);
		x--;
	}
}

void	ft_putnbr(int nb)
{
	int		temp;
	int		x;

	x = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * (-1);
	}
	temp = nb;
	verif0(nb);
	while (temp >= 1)
	{
		temp = temp / 10;
		x++;
	}
	calcul_response(nb, x);
}
/*
int	main(void)
{
	ft_putnbr(42);
}
*/