/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:35:04 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/04 11:20:42 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_program_error(char *error)
{
	ft_putendl_fd(ft_strjoin("Error\n\033[1;31m", error), 2);
	exit (EXIT_FAILURE);
}

void	exit_program_peacefully(t_mlx *mlx, char *msg)
{
	(void)mlx;
	ft_putendl_fd(msg, 1);
	exit (EXIT_SUCCESS);
}

int	close_window(t_mlx *mlx)
{
	exit_program_peacefully(mlx, "Window closed.");
	exit (EXIT_SUCCESS);
}
