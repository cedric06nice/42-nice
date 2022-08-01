/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:07:20 by elombard          #+#    #+#             */
/*   Updated: 2022/08/01 17:37:56 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_square	find_best_square(t_square square, t_square best_square);
int			is_obstacle(char **board, t_square square, t_board_info board_info);

void	find_square(char **board, t_board_info	board_info)
{
	t_square	square;
	t_square	best_square;

	square.x = 0;
	square.y = 0;
	square.size = 0;
	while (square.y < board_info.y)
	{
		while (square.x < board_info.x)
		{
			if (!is_obstacle(board, square, board_info))
				square.size++;
			else
				best_square = find_best_square(square, best_square);
			square.x++;
		}
		square.x = 0;
		square.y++;
	}
}

t_square	find_best_square(t_square square, t_square best_square)
{
	if (square.size > best_square.size)
		return (square);
	return (best_square);
}

int	is_obstacle(char **board, t_square square, t_board_info board_info)
{
	unsigned int	i;
	unsigned int	j;

	i = square.x + square.size;
	j = square.y + square.size;
	while (i > square.x)
	{
		if (board[i][j] == board_info.obstacle)
			return (1);
		i--;
	}
	while (j > square.y)
	{
		if (board[i][j] == board_info.obstacle)
			return (1);
		j--;
	}
	return (0);
}

void	print_board(char **board, t_board_info board_info)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < board_info.x)
	{
		j = 0;
		while (j < board_info.y)
		{
			write(1, &board[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
