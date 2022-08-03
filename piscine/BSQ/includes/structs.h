/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 09:27:42 by cpugnair          #+#    #+#             */
/*   Updated: 2022/08/02 09:00:39 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_board_info {
	unsigned int	x;
	unsigned int	y;
	char			empty;
	char			obstacle;
	char			full;
}	t_board_info;

typedef struct s_square {
	unsigned int	x;
	unsigned int	y;
	unsigned int	size;
}	t_square;

#endif