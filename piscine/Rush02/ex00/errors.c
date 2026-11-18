/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:49:02 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/31 22:37:08 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	print_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	print_dict_error(void)
{
	write(1, "Dict Error\n", 11);
	return (1);
}
