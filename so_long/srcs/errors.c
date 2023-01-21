/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:35:04 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/20 20:10:08 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		print_errors(char *error)
{
	ft_putendl_fd(ft_strjoin(ft_strjoin("Error\n\033[1;31m", error), "\033[0m") , 2);
	return (-1);
}

void	exit_program(t_mlx *mlx, char *error)
{
	ft_putendl_fd(error, 2);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free(mlx);
	exit(0);
}
