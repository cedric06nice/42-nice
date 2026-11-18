/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 23:32:41 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/03 13:57:08 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
** Write a function that returns a line read from a file descriptor
** Parameters fd: The file descriptor to read from
** Return value Read line: correct behavior
** NULL: there is nothing else to read, or an error occurred
*/

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(left_str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buffer), NULL);
		buffer[read_bytes] = '\0';
		left_str = ft_strjoin(left_str, buffer);
	}
	return (free(buffer), left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer[fd] = ft_read_to_left_str(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_new_left_str(buffer[fd]);
	return (line);
}
