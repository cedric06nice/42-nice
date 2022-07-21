/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:05:24 by fabperei          #+#    #+#             */
/*   Updated: 2022/07/16 12:58:51 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	line(int x, char start, char middle, char end);

void	rush(int x, int y)
{
	int	a;

	a = 0;
	if (y <= 1)
	{
		line(x, 'A', 'B', 'C');
	}
	else if (y == 2)
	{
		line(x, 'A', 'B', 'C');
		line(x, 'A', 'B', 'C');
	}
	else
	{
		line(x, 'A', 'B', 'C');
		while (a < y - 2)
		{
			line(x, 'B', ' ', 'B');
			a++;
		}
		line(x, 'A', 'B', 'C');
	}
}
