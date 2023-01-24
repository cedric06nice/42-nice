/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:04:15 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/24 20:41:32 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int		explore(t_mlx *mlx, int x, int y)
{
	if (x < 0 || y < 0 || x >= mlx->nb_cols || y >= mlx->nb_rows)
		return (0);
	if (mlx->map[y][x] == WALL)
		return (0);
	if (mlx->map[y][x] == EXIT && mlx->nb_collectibles == 0)
		return (1);
	else
	{
		if (mlx->map[y][x] == COLLECTIBLE)
			mlx->nb_collectibles--;
		if (mlx->map[y][x] == EMPTY || mlx->map[y][x] == PLAYER
			|| mlx->map[y][x] == COLLECTIBLE)
		{
			mlx->map[y][x] = '.';
			if (explore(mlx, x + 1, y))
				return (1);
			if (explore(mlx, x - 1, y))
				return (1);
			if (explore(mlx, x, y + 1))
				return (1);
			if (explore(mlx, x, y - 1))
				return (1);
			mlx->map[y][x] = '0';
		}
	}
	return (0);
}

int 	bactracking(t_mlx *mlx_original)
{
	t_mlx	*mlx;
	int		valid;

	mlx = malloc(sizeof(t_mlx));
	ft_memcpy(mlx, mlx_original, sizeof(t_mlx));
	valid = explore(mlx, mlx->player.position_x, mlx->player.position_y);
	if (valid)
		return (free(mlx), 1);
	else
	{
		free(mlx);
		exit_program_error("Map canot be solved.");
	}
	return (0);
}
