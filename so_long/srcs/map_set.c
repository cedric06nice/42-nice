/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:28:46 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/21 08:56:41 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void		set_nb_rows(t_mlx *mlx, char *file)
{
	int		fd;
	int		rows;
	char	*line;

	rows = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			mlx->nb_rows = rows;
			break ;
		}
		rows++;
		free(line);
	}
}

static void 	set_nb_cols(t_mlx *mlx, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	mlx->nb_cols = ft_strlen(line) - 1;
	free(line);
}

void 			set_map_size(t_mlx *mlx, char *file)
{
	set_nb_rows(mlx, file);
	set_nb_cols(mlx, file);
	mlx->win_width = mlx->nb_cols * TILE_SIZE;
	mlx->win_height = mlx->nb_rows * TILE_SIZE;
}

static int		count_map_items(t_mlx *mlx, char c)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (i < mlx->nb_rows)
	{
		j = 0;
		while (j < mlx->nb_cols)
		{
			if (mlx->map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int				set_map_items(t_mlx *mlx)
{
	if (!mlx->map)
		return (print_errors("Map must be set before setting items."));
	
	mlx->nb_players = count_map_items(mlx, PLAYER);
	mlx->nb_exits = count_map_items(mlx, EXIT);
	mlx->nb_collectibles = count_map_items(mlx, COLLECTIBLE);
	mlx->nb_moves = 0;
	return (0);
}
