/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:17:50 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/23 23:37:03 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		keyboard_key_pressed(int keycode, t_mlx *mlx)
{
	if (keycode == LEFT || keycode == ARROW_LEFT
		|| keycode == RIGHT || keycode == ARROW_RIGHT
		|| keycode == UP || keycode == ARROW_UP
		|| keycode == DOWN || keycode == ARROW_DOWN)
		player_direction(mlx, keycode);
	else if (keycode == ESC)
		close_window(mlx);
	return (keycode);
}
