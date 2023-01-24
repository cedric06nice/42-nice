/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:31:39 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/23 23:35:29 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_direction(t_mlx *mlx, int keycode)
{
	if (keycode == UP || keycode == ARROW_UP)
		player_move(mlx, mlx->player.position_x, mlx->player.position_y - 1);
	else if (keycode == DOWN || keycode == ARROW_DOWN)
		player_move(mlx, mlx->player.position_x, mlx->player.position_y + 1);
	else if (keycode == LEFT || keycode == ARROW_LEFT)
		player_move(mlx, mlx->player.position_x - 1, mlx->player.position_y);
	else if (keycode == RIGHT || keycode == ARROW_RIGHT)
		player_move(mlx, mlx->player.position_x + 1, mlx->player.position_y);
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
		mlx->player.position_x = to_x;
		mlx->player.position_y = to_y;
		mlx->player.nb_moves++;
	}
	else if (mlx->map[to_y][to_x] == COLLECTIBLE)
	{
		mlx->map[y][x] = EMPTY;
		mlx->map[to_y][to_x] = PLAYER;
		mlx->player.position_x = to_x;
		mlx->player.position_y = to_y;
		mlx->nb_collectibles--;
		mlx->player.nb_moves++;
	}
	else if (mlx->map[to_y][to_x] == EXIT && mlx->nb_collectibles == 0)
	{
		mlx->player.nb_moves++;
		close_window(mlx);
	}
	// print_map(mlx);
}
