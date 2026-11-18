/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:05:34 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/30 01:52:05 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_error(void)
{
	ft_printf("\n%sClient: Unexpected error.%s\n", RED, END);
	exit (-1);
}

void	char_to_bin(unsigned char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 128)
		{
			if (kill(pid, SIGUSR2) == -1)
				signal_error();
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				signal_error();
		}
		c <<= 1;
		bit++;
		pause();
		usleep(100);
	}
}

void	sent_text(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
		char_to_bin(str[i++], pid);
	char_to_bin('\0', pid);
}

void	received(int sig)
{
	static int	sent;

	if (sig == SIGUSR1)
	{
		ft_printf("%s%d signals sent successfully!%s\n", GREEN, ++sent, END);
		exit (0);
	}
	if (sig == SIGUSR2)
		++sent;
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("%sUsage: ./client <server_pid> <text>%s\n", RED, END);
		return (-1);
	}
	ft_printf("%sClient's PID: %d%s\n", RED, getpid(), END);
	signal(SIGUSR1, received);
	signal(SIGUSR2, received);
	sent_text(av[2], ft_atoi(av[1]));
	return (0);
}
