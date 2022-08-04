/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:59:18 by cpugnair          #+#    #+#             */
/*   Updated: 2022/08/03 18:13:40 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
** Prints map error message on the standard error output.
*/
void	print_map_error(void)
{
	write(2, "map error\n", 11);
}
