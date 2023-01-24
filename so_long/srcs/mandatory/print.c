/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:07:54 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/24 20:43:48 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_details(t_mlx *mlx)
{
	ft_putendl_fd("****** DETAILS ******", 1);
	ft_printf("mlx->nb_rows = %d\n", mlx->nb_rows);
	ft_printf("mlx->nb_cols = %d\n", mlx->nb_cols);
	ft_printf("mlx->win_height = %d\n", mlx->win_height);
	ft_printf("mlx->win_width = %d\n", mlx->win_width);
	ft_printf("mlx->win_name = %s\n", mlx->win_name);
	ft_printf("mlx->nb_players = %d\n", mlx->nb_players);
	ft_printf("mlx->nb_exits = %d\n", mlx->nb_exits);
	ft_printf("mlx->exit_pos_x = %d\n", mlx->exit_pos_x);
	ft_printf("mlx->exit_pos_y = %d\n", mlx->exit_pos_y);
	ft_printf("mlx->nb_collectibles = %d\n", mlx->nb_collectibles);
	ft_printf("player->position_x = %d\n", mlx->player.position_x);
	ft_printf("player->position_y = %d\n", mlx->player.position_y);
	ft_printf("player->nb_moves = %d\n", mlx->player.nb_moves);
	ft_putendl_fd(" ", 1);
}

void	print_map(t_mlx *mlx)
{
	int		row;
	int		col;

	ft_putendl_fd(" ", 1);
	ft_putendl_fd("** MAP START **", 1);
	row = 0;
	while (row < mlx->nb_rows)
	{
		col = 0;
		while (col < mlx->nb_cols)
		{
			if (mlx->map[row][col] == EMPTY)
				ft_printf("   ");
			else if (mlx->map[row][col] == WALL)
				ft_printf(" X ");
			else
				ft_printf(" %c ", mlx->map[row][col]);
			col++;
		}
		ft_printf("\n");
		row++;
	}
	ft_printf("Number of moves: %d\n", mlx->player.nb_moves);
	ft_printf("Number of collectibles left: %d\n", mlx->nb_collectibles);
}
