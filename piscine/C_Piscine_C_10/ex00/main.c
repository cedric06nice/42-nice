/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:43:09 by cpugnair          #+#    #+#             */
/*   Updated: 2022/08/03 13:27:02 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	file_exists(char *filename)
{
	int	fd;

	fd = open(filename, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (0);
	}
	fd = open(filename, 0);
	if (fd == -1)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	is_errors(int argc)
{
	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	else if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	else
		return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	str[10000];
	int		i;

	fd = 0;
	i = 1;
	if (!is_errors(argc))
	{
		if (file_exists(argv[1]))
		{
			fd = open(argv[1], O_RDONLY);
			read(fd, str, 10000);
			while (str[i])
			{
				write(1, &str[i], 1);
				i++;
			}
		}
		else
			write(2, "Cannot read file.\n", 18);
	}
	return (0);
}
