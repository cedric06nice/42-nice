/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:14:51 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/21 09:01:10 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int  	set_map(t_mlx *mlx, char *file)
{
	int		fd;
	int		row;
	int		col;
	char	*line;

	mlx->map = malloc(sizeof(char *) * mlx->nb_rows);
	if (!mlx->map)
		return (print_errors("Malloc failed"));
	row = 0;
	fd = open(file, O_RDONLY);
	while (row < mlx->nb_rows)
	{
		mlx->map[row] = malloc(sizeof(char) * mlx->nb_cols);
		if (!mlx->map[row])
			return (print_errors("Malloc failed"));
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
}
