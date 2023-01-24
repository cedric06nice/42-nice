/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:38:45 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/24 20:41:50 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int		check_arguments(int argc, char **argv)
{
	int		fd;

	if (argc == 1)
		exit_program_error("No map has been provided.");
	if (argc > 2)
		exit_program_error("Too many arguments have been provided.");
	if (ft_strlen(argv[1]) < 5)
		exit_program_error("Wrong file name");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		exit_program_error("Map must be a .ber file.");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_program_error(ft_strjoin("Cannot open the file ", argv[1]));
	close(fd);
	return (0);
}

int		check_map_size(t_mlx *mlx)
{
	if (mlx->nb_rows < 3 || mlx->nb_cols < 3)
		exit_program_error("The map is too small.");
	if (mlx->nb_rows > 27 || mlx->nb_cols > 47)
		exit_program_error("The map is too big.");
	return (0);
}

int		check_map_surroundings(t_mlx *mlx)
{
	int		row;
	int		col;

	row = 0;
	while (row < mlx->nb_rows)
	{
		col = 0;
		while (col < mlx->nb_cols)
		{
			if ((row == 0 || row == mlx->nb_rows - 1)
				|| (col == 0 || col == mlx->nb_cols - 1))
			{
				if (mlx->map[row][col] != WALL)
					exit_program_error("The map must be surrounded by walls.");
			}
			col++;
		}
		row++;
	}
	return (0);
}

int		check_map_items(t_mlx *mlx)
{
	if (mlx->nb_players != 1)
		exit_program_error("The map must contain exactly one player.");
	if (mlx->nb_exits != 1)
		exit_program_error("The map must contain exactly one exit.");
	if (mlx->nb_collectibles < 1)
		exit_program_error("The map must contain at least one collectible.");
	return (0);
}
