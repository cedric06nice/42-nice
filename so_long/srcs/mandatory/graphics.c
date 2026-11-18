/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:21:15 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/04 11:54:37 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_graphics(t_mlx *mlx)
{
	mlx->img.img[0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			COLLECTIBLE_IMG, &mlx->img.img_width, &mlx->img.img_height);
	mlx->img.img[1] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			EMPTY_IMG, &mlx->img.img_width, &mlx->img.img_height);
	mlx->img.img[2] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			EXIT_CLOSE_IMG, &mlx->img.img_width, &mlx->img.img_height);
	mlx->img.img[3] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			PLAYER_IMG, &mlx->img.img_width, &mlx->img.img_height);
	mlx->img.img[4] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			WALL_IMG, &mlx->img.img_width, &mlx->img.img_height);
	if (!mlx->img.img[0] || !mlx->img.img[1] || !mlx->img.img[2]
		|| !mlx->img.img[3] || !mlx->img.img[4])
		exit_program_error("Failed to load graphics.");
}

void	put_image_c(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img[1], x, y);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img[0], x, y);
}

void	put_image_p(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img[1], x, y);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img[3], x, y);
}

void	put_image(t_mlx *mlx, char map, int x, int y)
{
	if (map == 'C')
		put_image_c(mlx, x, y);
	if (map == '0')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->img.img[1], x, y);
	else if (map == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->img.img[2], x, y);
	else if (map == 'P')
		put_image_p(mlx, x, y);
	else if (map == '1')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->img.img[4], x, y);
}

int	draw_graphics(t_mlx *mlx)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	y = 0;
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
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
