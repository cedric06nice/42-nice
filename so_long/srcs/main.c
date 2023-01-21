/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:45:55 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/21 09:35:26 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_details(t_mlx *mlx)
{
	ft_printf("mlx->nb_rows = %d\n", mlx->nb_rows);
	ft_printf("mlx->nb_cols = %d\n", mlx->nb_cols);
	ft_printf("mlx->win_height = %d\n", mlx->win_height);
	ft_printf("mlx->win_width = %d\n", mlx->win_width);
	ft_printf("mlx->win_name = %s\n", mlx->win_name);
	ft_printf("mlx->nb_players = %d\n", mlx->nb_players);
	ft_printf("mlx->nb_exits = %d\n", mlx->nb_exits);
	ft_printf("mlx->nb_collectibles = %d\n", mlx->nb_collectibles);
	ft_printf("mlx->nb_moves = %d\n", mlx->nb_moves);
	int i = 0;
	while (i < mlx->nb_rows)
	{
		int j = 0;
		while (j < mlx->nb_cols)
		{
			ft_printf(" %c ", mlx->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int		key_hook(int keycode, void *param)
{
	(void)param;
	ft_putendl_fd(ft_itoa(keycode), 1);
	return (keycode);
}

int main(int argc, char **argv)
{
	t_mlx	*mlx;
	int		key;
	key = 0;

	if (check_arguments(argc, argv) == -1)
		exit (0);
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (print_errors("Malloc failed."));
	mlx->win_name = "so_long";
	load_map(mlx, argv[1]);
	print_details(mlx);
	
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return (free(mlx), 1);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_width, mlx->win_height, mlx->win_name);
	if (mlx->win_ptr == NULL)
		return (free(mlx), 1);
	key = mlx_key_hook(mlx->win_ptr, key_hook, (void *)0);
	ft_putendl_fd(ft_itoa(key), 1);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, 0x00FFFFFF, ft_itoa(key));
	mlx_loop(mlx->mlx_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free(mlx);
	return (0);
}
