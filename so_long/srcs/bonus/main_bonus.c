/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:45:55 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/04 19:16:20 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	string_mlx(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 20, 0x00FFFFFF,
		ft_strjoin("Moves: ", ft_itoa(mlx->player.nb_moves)));
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 40, 0x00FFFFFF,
		ft_strjoin("Items: ", ft_itoa(mlx->nb_collectibles)));
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (check_arguments(argc, argv) == -1)
		exit_program_error("Bad arguments");
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		exit_program_error("Malloc failed.");
	mlx->win_name = "so_long";
	load_map(mlx, argv[1]);
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return (free(mlx), EXIT_FAILURE);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_width,
			mlx->win_height, mlx->win_name);
	if (mlx->win_ptr == NULL)
		return (free(mlx), EXIT_FAILURE);
	load_graphics(mlx);
	mlx_loop_hook(mlx->mlx_ptr, draw_graphics, mlx);
	mlx_key_hook(mlx->win_ptr, keyboard_key_pressed, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, close_window, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (EXIT_SUCCESS);
}
