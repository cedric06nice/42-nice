/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:14:26 by cpugnair          #+#    #+#             */
/*   Updated: 2022/08/03 10:34:53 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	count_digit(int nb)
{
	int		count;

	count = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

void	print_numbers(int a)
{
	char	nb;

	nb = '0' + a / 10;
	write(1, &nb, 1);
	nb = '0' + a - (a / 10 * 10);
	write(1, &nb, 1);
}

void	ft_print_combn(int n)
{
	int	nb_digits;
	int	nb1;

	nb_digits = count_digit(n);
	nb1 = 0;
	while (nb1 < (nb_digits * 10))
	{
		print_numbers(nb1);
		write(1, ", ", 2);
		nb1++;
	}
}

int	main(void)
{
	ft_print_combn(1);
	return (0);
}
