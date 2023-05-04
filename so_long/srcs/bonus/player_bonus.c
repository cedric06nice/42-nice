/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:31:39 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/04 19:27:22 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	keyboard_key_pressed(int keycode, t_mlx *mlx)
{
	if (keycode == LEFT || keycode == ARROW_LEFT
		|| keycode == RIGHT || keycode == ARROW_RIGHT
		|| keycode == UP || keycode == ARROW_UP
		|| keycode == DOWN || keycode == ARROW_DOWN)
		player_direction(mlx, keycode);
	else if (keycode == ESC)
		close_window(mlx);
	return (keycode);
}

void	player_direction(t_mlx *mlx, int keycode)
{
	if (keycode == UP || keycode == ARROW_UP)
	{
		mlx->player.direction = 'U';
		player_move(mlx, mlx->player.position_x, mlx->player.position_y - 1);
	}
	else if (keycode == DOWN || keycode == ARROW_DOWN)
	{
		mlx->player.direction = 'D';
		player_move(mlx, mlx->player.position_x, mlx->player.position_y + 1);
	}
	else if (keycode == LEFT || keycode == ARROW_LEFT)
	{
		mlx->player.direction = 'L';
		player_move(mlx, mlx->player.position_x - 1, mlx->player.position_y);
	}
	else if (keycode == RIGHT || keycode == ARROW_RIGHT)
	{
		mlx->player.direction = 'R';
		player_move(mlx, mlx->player.position_x + 1, mlx->player.position_y);
	}
}

void	move_player(t_mlx *mlx, int to_x, int to_y)
{
	mlx->player.position_x = to_x;
	mlx->player.position_y = to_y;
	mlx->player.nb_moves++;
}

void	player_move(t_mlx *mlx, int to_x, int to_y)
{
	int		x;
	int		y;

	x = mlx->player.position_x;
	y = mlx->player.position_y;
	if (mlx->map[to_y][to_x] == EMPTY)
	{
		mlx->map[y][x] = EMPTY;
		mlx->map[to_y][to_x] = PLAYER;
		move_player(mlx, to_x, to_y);
	}
	else if (mlx->map[to_y][to_x] == COLLECTIBLE)
	{
		mlx->map[y][x] = EMPTY;
		mlx->map[to_y][to_x] = PLAYER;
		move_player(mlx, to_x, to_y);
		mlx->nb_collectibles--;
	}
	else if (mlx->map[to_y][to_x] == EXIT && mlx->nb_collectibles == 0)
	{
		mlx->player.nb_moves++;
		close_window(mlx);
	}
}
