/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:43:39 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/30 01:39:08 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_error(void)
{
	ft_printf("\n%sServer: Unexpected error.%s\n", RED, END);
	exit (-1);
}

void	extended_action(char *c, int *received, int *client_pid, int *bit)
{
	ft_printf("%c", *c);
	if (*c == '\0')
	{
		ft_printf("\n%s%d signals recieved from client PID: %d%s\n",
			GREEN, *received, *client_pid, END);
		*received = 0;
		*c = 0;
		if (kill(*client_pid, SIGUSR1) == -1)
			signal_error();
		return ;
	}
	*bit = 0;
}

void	action(int sig, siginfo_t *info, void *context)
{
	static int	client_pid;
	static int	bit;
	static char	c;
	static int	received;
	static int	current_pid;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	current_pid = info->si_pid;
	if (client_pid != current_pid)
	{
		client_pid = current_pid;
		bit = 0;
		c = 0;
		received = 0;
	}
	c |= (sig == SIGUSR2);
	received++;
	bit++;
	if (bit == 8)
		extended_action(&c, &received, &client_pid, &bit);
	c <<= 1;
	usleep(100);
	kill(client_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("%sServer's PID: %d%s\n", RED, getpid(), END);
	sa.sa_sigaction = action;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	while (6)
	{
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
		pause();
	}
	return (-1);
}
