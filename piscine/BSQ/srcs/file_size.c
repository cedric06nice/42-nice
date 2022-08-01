/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:43:18 by elombard          #+#    #+#             */
/*   Updated: 2022/08/01 17:38:40 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
** Calculate the file's buffer size
*/
int	file_size(char *file)
{
	int		fd;
	char	c;
	int		size;

	size = 0;
	fd = open(file, 0);
	while (read(fd, &c, 1))
		size++;
	close(fd);
	return (size);
}
