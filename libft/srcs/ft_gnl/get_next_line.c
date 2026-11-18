/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 23:32:41 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/04 10:16:18 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Write a function that returns a line read from a file descriptor
** Parameters fd: The file descriptor to read from
** Return value Read line: correct behavior
** NULL: there is nothing else to read, or an error occurred
*/
char	*ft_get_next_line(int fd)
{
	char		*line;
	static char	*buffer[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer[fd] = read_to_left_str(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = get_line(buffer[fd]);
	buffer[fd] = new_left_str(buffer[fd]);
	return (line);
}

char	*read_to_left_str(int fd, char *left_str)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!gnl_strchr(left_str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buffer), NULL);
		buffer[read_bytes] = '\0';
		left_str = gnl_strjoin(left_str, buffer);
	}
	return (free(buffer), left_str);
}

char	*get_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
		return (free(left_str), NULL);
	str = (char *)malloc(sizeof(char) * (gnl_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	return (free(left_str), str);
}
