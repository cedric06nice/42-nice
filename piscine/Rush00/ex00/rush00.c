/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:05:24 by fabperei          #+#    #+#             */
/*   Updated: 2022/07/16 12:54:49 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	line(int x, char start, char middle, char end);

void	rush(int x, int y)
{
	int	a;

	a = 0;
	if (y <= 1)
	{
		line(x, 'o', '-', 'o');
	}
	else if (y == 2)
	{
		line(x, 'o', '-', 'o');
		line(x, 'o', '-', 'o');
	}
	else
	{
		line(x, 'o', '-', 'o');
		while (a < y - 2)
		{
			line(x, '|', ' ', '|');
			a++;
		}
		line(x, 'o', '-', 'o');
	}
}
