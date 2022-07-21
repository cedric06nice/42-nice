/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:23:15 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/17 10:55:16 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	puissance(int n)
{
	int	puissance;

	puissance = 0;
	if (n >= 1)
	{
		puissance = 1;
		n--;
	}
	while (n != 0)
	{
		puissance = puissance * 10;
		n--;
	}
	return (puissance);
}

void	verif0(int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
	}
}

void	calcul_reponse(int nb, int x)
{
	char	rep;
	int		res;

	while (x > 0)
	{
		res = nb / puissance(x);
		nb = nb - (res * puissance(x));
		rep = '0' + res;
		if (res != 0)
		{
			write(1, &rep, 1);
		}
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
	calcul_reponse(nb, x);
}