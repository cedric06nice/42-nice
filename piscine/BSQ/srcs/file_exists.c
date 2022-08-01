/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_exists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:50:34 by elombard          #+#    #+#             */
/*   Updated: 2022/08/01 17:38:40 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
**	Check if the file exists
*/
int	file_exists(char *filename)
{
	int	file;

	file = open(filename, 0);
	if (file == -1)
		return (0);
	close(file);
	return (1);
}
