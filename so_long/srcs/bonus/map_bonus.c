/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:14:51 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/04 08:34:40 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	set_nb_rows(t_mlx *mlx, char *file)
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

static void	set_nb_cols(t_mlx *mlx, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	mlx->nb_cols = ft_strlen(line) - 1;
	free(line);
}

static void	set_map_size(t_mlx *mlx, char *file)
{
	set_nb_rows(mlx, file);
	set_nb_cols(mlx, file);
	mlx->win_width = mlx->nb_cols * TILE_SIZE;
	mlx->win_height = mlx->nb_rows * TILE_SIZE + HEADER_SIZE;
}

static int	set_map(t_mlx *mlx, char *file)
{
	int		fd;
	int		row;
	int		col;
	char	*line;

	mlx->map = malloc(sizeof(char *) * mlx->nb_rows);
	if (!mlx->map)
		exit_program_error("Malloc failed");
	row = 0;
	fd = open(file, O_RDONLY);
	while (row < mlx->nb_rows)
	{
		mlx->map[row] = malloc(sizeof(char) * mlx->nb_cols);
		if (!mlx->map[row])
			exit_program_error("Malloc failed");
		col = 0;
		line = get_next_line(fd);
		while (col < mlx->nb_cols)
		{
			mlx->map[row][col] = line[col];
			col++;
		}
		free(line);
		row++;
	}
	return (0);
}

void	load_map(t_mlx *mlx, char *file)
{
	set_map_size(mlx, file);
	check_map_size(mlx);
	set_map(mlx, file);
	check_map_surroundings(mlx);
	set_map_items(mlx);
	check_map_items(mlx);
	bactracking(mlx);
	set_map(mlx, file);
}
