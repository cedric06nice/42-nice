/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:44:08 by cpugnair          #+#    #+#             */
/*   Updated: 2022/08/03 09:10:44 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
** Print the board by replacing empty by full if necessary.
*/
void	print_board(char **board, t_board_info info, t_square square)
{
	unsigned int	x;
	unsigned int	y;

	y = 1;
	while (y <= info.y)
	{
		x = 0;
		while (x < info.x)
		{
			if (x >= square.x && x < square.x + square.size
				&& y >= square.y && y < square.y + square.size)
				write(1, &info.full, 1);
			else if (board[y][x] == info.empty)
				write(1, &info.empty, 1);
			else if (board[y][x] == info.obstacle)
				write(1, &info.obstacle, 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
