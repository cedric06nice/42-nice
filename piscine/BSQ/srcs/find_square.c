/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:07:20 by elombard          #+#    #+#             */
/*   Updated: 2022/08/03 10:10:41 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	find_square(char **board, t_board_info info)
{
	t_square	square;
	t_square	best_square;

	init_squares(&square, &best_square);
	while (square.y <= info.y - square.size)
	{
		while (square.x < info.x - square.size)
		{
			while (!is_obstacle(board, square, info))
			{
				square.size++;
				is_obstacle(board, square, info);
			}
			best_square = find_best_square(square, best_square);
			square.x++;
			square.size = 0;
		}
		square.x = 0;
		square.y++;
	}
	print_board(board, info, best_square);
}

void	init_squares(t_square *square, t_square *best_square)
{
	square->x = 0;
	square->y = 1;
	square->size = 0;
	best_square->x = 0;
	best_square->y = 1;
	best_square->size = 0;
}

int	is_obstacle(char **board, t_square square, t_board_info info)
{
	unsigned int	i_min;
	unsigned int	i_max;
	unsigned int	j_min;
	unsigned int	j_max;

	i_min = square.x;
	i_max = square.x + square.size;
	j_min = square.y;
	j_max = square.y + square.size;
	while (i_min <= i_max)
	{
		if (board[j_max][i_min] == info.obstacle || i_min == info.x)
			return (1);
		i_min++;
	}
	while (j_min <= j_max)
	{
		if (board[j_min][i_max] == info.obstacle || j_min == info.y)
			return (1);
		j_min++;
	}
	return (0);
}

t_square	find_best_square(t_square square, t_square best_square)
{
	if (square.size > best_square.size)
		return (square);
	return (best_square);
}
