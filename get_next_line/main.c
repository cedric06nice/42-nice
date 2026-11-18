/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:22:48 by cpugnair          #+#    #+#             */
/*   Updated: 2022/12/23 17:23:39 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/time.h>

static void	gnl(int fd)
{
	char	*s;

	s = get_next_line(fd);
	printf("%s", s);
	free(s);
}

int	main(void)
{
	int				fd;
	int				fd2;
	struct timeval	start;
	struct timeval	end;
	long			seconds;
	long			microseconds;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	gettimeofday(&start, NULL);
	/* invalid fd */
	gnl(1000);
	gnl(-1);
	for (int i = 0; i < 6; i++)
	{
		gnl(fd);
		gnl(fd2);
	}
	gettimeofday(&end, NULL);
	seconds = (end.tv_sec - start.tv_sec);
	microseconds = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
	printf("\n\033[0;32mThis code took %ld,%ld seconds to run.\033[0m\n",
		(microseconds / 1000000), (microseconds % 1000000));
	system("leaks a.out");
	close(fd);
	close(fd2);
	return (0);

	// int fd = open("read_error.txt", O_RDONLY);
	// char *s = get_next_line(fd);
	// while (s != NULL)
	// {
	// 	printf("%s", s);
	// 	free(s);
	// 	s = get_next_line(fd);
	// }
	// close(fd);
	// fd = open("read_error.txt", O_RDONLY);
	// s = get_next_line(fd);
	// while (s != NULL)
	// {
	// 	printf("%s", s);
	// 	free(s);
	// 	s = get_next_line(fd);
	// }
	// close(fd);
	// system("leaks a.out");
}
