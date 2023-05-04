/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:31:39 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/04 19:24:51 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyboard_key_pressed(int keycode, t_mlx *mlx)
{
	if (keycode == LEFT || keycode == RIGHT
		|| keycode == UP || keycode == DOWN)
		player_direction(mlx, keycode);
	else if (keycode == ESC)
		close_window(mlx);
	return (keycode);
}

void	player_direction(t_mlx *mlx, int keycode)
{
	if (keycode == UP)
		player_move(mlx, mlx->player.position_x, mlx->player.position_y - 1);
	else if (keycode == DOWN)
		player_move(mlx, mlx->player.position_x, mlx->player.position_y + 1);
	else if (keycode == LEFT)
		player_move(mlx, mlx->player.position_x - 1, mlx->player.position_y);
	else if (keycode == RIGHT)
		player_move(mlx, mlx->player.position_x + 1, mlx->player.position_y);
}

void	position(t_mlx *mlx, int to_x, int to_y)
{
	mlx->map[to_y][to_x] = PLAYER;
	mlx->player.position_x = to_x;
	mlx->player.position_y = to_y;
	mlx->player.nb_moves++;
	ft_printf("Number of moves: %d\n", mlx->player.nb_moves);
}

void	exit_game(t_mlx *mlx)
{
	if (mlx->nb_collectibles > 0)
		ft_printf("You still have %d collectible(s) to collect.\n",
			mlx->nb_collectibles);
	else
	{
		mlx->player.nb_moves++;
		ft_printf("Number of moves: %d\n", mlx->player.nb_moves);
		close_window(mlx);
	}
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
		position(mlx, to_x, to_y);
	}
	else if (mlx->map[to_y][to_x] == COLLECTIBLE)
	{
		mlx->map[y][x] = EMPTY;
		position(mlx, to_x, to_y);
		mlx->nb_collectibles--;
	}
	else if (mlx->map[to_y][to_x] == EXIT)
		exit_game(mlx);
}
