/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:23:15 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/14 15:26:12 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_numbers(int a, int b)
{
	char	nb;

	nb = '0' + a / 10;
	write(1, &nb, 1);
	nb = '0' + a - (a / 10 * 10);
	write(1, &nb, 1);
	write(1, " ", 1);
	nb = '0' + b / 10;
	write(1, &nb, 1);
	nb = '0' + b - (b / 10 * 10);
	write(1, &nb, 1);
}

void	ft_print_comb2(void)
{
	int	nb1;
	int	nb2;

	nb1 = 0;
	nb2 = 1;
	while (nb1 < 99)
	{
		while (nb2 < 100)
		{
			print_numbers(nb1, nb2);
			nb2++;
			if (nb1 != 98)
			{
				write(1, ",", 1);
				write(1, " ", 1);
			}
		}
		nb1++;
		nb2 = nb1 + 1;
	}
}
