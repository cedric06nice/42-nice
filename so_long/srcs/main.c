/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:45:55 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/18 10:44:09 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "My first window!");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return (1);
	}
	while (1)
		;
	// mlx_destroy_window(mlx_ptr, win_ptr);
	// mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
