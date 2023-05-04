/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:21:15 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/04 08:33:59 by cpugnair         ###   ########.fr       */
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

int	draw_graphics(t_mlx *mlx)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	y = HEADER_SIZE;
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 20, 0x00FFFFFF,
		ft_strjoin("Moves: ", ft_itoa(mlx->player.nb_moves)));
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 40, 0x00FFFFFF,
		ft_strjoin("Items: ", ft_itoa(mlx->nb_collectibles)));
	while (i < mlx->nb_rows)
	{
		j = 0;
		x = 0;
		while (j < mlx->nb_cols)
		{
			if (mlx->map[i][j] == 'C')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img[1], x, y);
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img[0], x, y);
			}
			if (mlx->map[i][j] == '0')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img[1], x, y);
			else if (mlx->map[i][j] == 'E')
			{
				if (mlx->nb_collectibles > 0)
					mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img[2], x, y);
				else
					mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img[5], x, y);
			}
			else if (mlx->map[i][j] == 'P')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img[1], x, y);
				if (mlx->player.direction == 'U')
					mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img[6], x, y);
				else if (mlx->player.direction == 'L')
					mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img[7], x, y);
				else if (mlx->player.direction == 'R')
					mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img[8], x, y);
				else
					mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img[3], x, y);
			}
			else if (mlx->map[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img[4], x, y);
			x += mlx->img.img_width;
			j++;
		}
		y += mlx->img.img_height;
		i++;
	}
	return (0);
}
