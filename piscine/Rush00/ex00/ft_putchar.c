/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 09:57:04 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/16 12:30:24 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	line(int x, char start, char middle, char end);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	line(int x, char start, char middle, char end)
{
	int	a;

	a = 0;
	if (x <= 1)
	{
		ft_putchar(start);
		ft_putchar('\n');
	}
	else if (x == 2)
	{
		ft_putchar(start);
		ft_putchar(end);
		ft_putchar('\n');
	}
	else
	{
		ft_putchar(start);
		while (a < x - 2)
		{
			ft_putchar(middle);
			a++;
		}
		ft_putchar(end);
		ft_putchar('\n');
	}
}
