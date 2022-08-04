/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:07:20 by elombard          #+#    #+#             */
/*   Updated: 2022/08/03 18:13:37 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
** Find the biggest square in the map
*/
void	find_square(char **board, t_board_info info)
{
	t_square	square;
	t_square	best_square;

	init_squares(&square, &best_square);
	while (square.y <= info.y)
	{
		while (square.x <= info.x)
		{
			while (!is_obstacle(board, square, info))
				square.size++;
			best_square = find_best_square(square, best_square);
			square.x++;
			square.size = 0;
		}
		square.x = 0;
		square.y++;
	}
	print_board(board, info, best_square);
}

/*
**	initialize the square and best_square coordinates and size
*/
void	init_squares(t_square *square, t_square *best_square)
{
	square->x = 0;
	square->y = 1;
	square->size = 0;
	best_square->x = 0;
	best_square->y = 1;
	best_square->size = 0;
}

/*
**	Check if the square will run into an obstacle
*/
int	is_obstacle(char **board, t_square square, t_board_info info)
{
	unsigned int	x_min;
	unsigned int	x_max;
	unsigned int	y_min;
	unsigned int	y_max;

	if (out_of_bounds(square, info))
		return (1);
	x_min = square.x;
	x_max = square.x + square.size;
	y_min = square.y;
	y_max = square.y + square.size;
	while (x_min <= x_max)
	{
		if (board[y_max][x_min] == info.obstacle)
			return (1);
		x_min++;
	}
	while (y_min <= y_max)
	{
		if (board[y_min][x_max] == info.obstacle)
			return (1);
		y_min++;
	}
	return (0);
}

/*
**	Check if the square's (coordinates + size) are out of bounds
*/
int	out_of_bounds(t_square square, t_board_info info)
{
	return (square.x + square.size >= info.x
		|| square.y + square.size > info.y);
}

/*
**	Find the best square by comparing the size of the current square to the
*/
t_square	find_best_square(t_square square, t_square best_square)
{
	if (square.size > best_square.size)
		return (square);
	return (best_square);
}
