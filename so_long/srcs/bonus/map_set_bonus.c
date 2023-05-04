/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:28:46 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/04 08:53:54 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	set_player_position(t_mlx *mlx, int pos_x, int pos_y)
{
	mlx->player.position_x = pos_x;
	mlx->player.position_y = pos_y;
}

static void	set_exit_position(t_mlx *mlx, int pos_x, int pos_y)
{
	mlx->exit_pos_x = pos_x;
	mlx->exit_pos_y = pos_y;
}

static int	count_map_items(t_mlx *mlx, char c)
{
	int		row;
	int		col;
	int		count;

	row = 0;
	count = 0;
	while (row < mlx->nb_rows)
	{
		col = 0;
		while (col < mlx->nb_cols)
		{
			if (mlx->map[row][col] == c)
			{
				if (c == PLAYER)
					set_player_position(mlx, col, row);
				else if (c == EXIT)
					set_exit_position(mlx, col, row);
				count++;
			}
			col++;
		}
		row++;
	}
	return (count);
}

int	set_map_items(t_mlx *mlx)
{
	if (!mlx->map)
		exit_program_error("Map must be set before setting items.");
	mlx->nb_collectibles = count_map_items(mlx, COLLECTIBLE);
	mlx->nb_exits = count_map_items(mlx, EXIT);
	mlx->nb_players = count_map_items(mlx, PLAYER);
	mlx->player.nb_moves = 0;
	return (0);
}
