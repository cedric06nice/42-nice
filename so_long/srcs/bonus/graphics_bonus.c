/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:21:15 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/04 19:15:45 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_graphics(t_mlx *mlx)
{
	mlx->img.img[0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			COLLECTIBLE_IMG, &mlx->img.img_width, &mlx->img.img_height);
	mlx->img.img[1] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			EMPTY_IMG, &mlx->img.img_width, &mlx->img.img_height);
	mlx->img.img[2] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			EXIT_CLOSE_IMG, &mlx->img.img_width, &mlx->img.img_height);
	mlx->img.img[3] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			PLAYER_DOWN_IMG, &mlx->img.img_width, &mlx->img.img_height);
	mlx->img.img[4] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			WALL_IMG, &mlx->img.img_width, &mlx->img.img_height);
	mlx->img.img[5] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			EXIT_OPEN_IMG, &mlx->img.img_width, &mlx->img.img_height);
	mlx->img.img[6] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			PLAYER_UP_IMG, &mlx->img.img_width, &mlx->img.img_height);
	mlx->img.img[7] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			PLAYER_LEFT_IMG, &mlx->img.img_width, &mlx->img.img_height);
	mlx->img.img[8] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			PLAYER_RIGHT_IMG, &mlx->img.img_width, &mlx->img.img_height);
	if (!mlx->img.img[0] || !mlx->img.img[1] || !mlx->img.img[2]
		|| !mlx->img.img[3] || !mlx->img.img[4] || !mlx->img.img[5]
		|| !mlx->img.img[6] || !mlx->img.img[7] || !mlx->img.img[8])
		exit_program_error("Failed to load graphics.");
}

void	put_image_to_window(t_mlx *mlx, int img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->img.img[img], x, y);
}

void	put_image_direction(t_mlx *mlx, char direction, int x, int y)
{
	put_image_to_window(mlx, 1, x, y);
	if (direction == 'U')
		put_image_to_window(mlx, 6, x, y);
	else if (direction == 'L')
		put_image_to_window(mlx, 7, x, y);
	else if (direction == 'R')
		put_image_to_window(mlx, 8, x, y);
	else
		put_image_to_window(mlx, 3, x, y);
}

void	put_image(t_mlx *mlx, char map, int x, int y)
{
	if (map == 'C')
	{
		put_image_to_window(mlx, 1, x, y);
		put_image_to_window(mlx, 0, x, y);
	}
	if (map == '0')
		put_image_to_window(mlx, 1, x, y);
	else if (map == 'E')
	{
		if (mlx->nb_collectibles > 0)
			put_image_to_window(mlx, 2, x, y);
		else
			put_image_to_window(mlx, 5, x, y);
	}
	else if (map == 'P')
		put_image_direction(mlx, mlx->player.direction, x, y);
	else if (map == '1')
		put_image_to_window(mlx, 4, x, y);
}

int	draw_graphics(t_mlx *mlx)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	y = HEADER_SIZE;
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	string_mlx(mlx);
	while (i < mlx->nb_rows)
	{
		j = 0;
		x = 0;
		while (j < mlx->nb_cols)
		{
			put_image(mlx, mlx->map[i][j], x, y);
			x += mlx->img.img_width;
			j++;
		}
		y += mlx->img.img_height;
		i++;
	}
	return (0);
}
