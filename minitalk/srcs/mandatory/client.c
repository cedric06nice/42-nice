/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:05:34 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/29 13:06:24 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_data_recieved;

int	send_string(t_data data)
{
	int		i;
	int		j;

	i = -1;
	while (data.str[++i])
	{
		j = 128;
		while (j >= 1)
		{
			if (g_data_recieved == 1)
			{
				if (j & data.str[i])
				{
					if (kill(data.pid, SIGUSR1) == -1)
						print_error("Error in sending signal!\n");
				}
				else
				{
					if (kill(data.pid, SIGUSR2) == -1)
						print_error("Error in sending signal!\n");
				}
				j /= 2;
				g_data_recieved = 0;
			}
			usleep(10000);
		}
	}
	return (0);
}

void	client_handler(int signum, siginfo_t *siginfo, void *uap)
{
	(void)uap;
	(void)siginfo;
	(void)signum;
	g_data_recieved = 1;
	write(1, "Signal received from server\n", 28);
	return ;
}

int	main(int argc, char **argv)
{
	t_data	data;

	g_data_recieved = 1;
	if (argc != 3)
		print_error("Wrong amount of arguments.");
	data.pid = ft_atoi(argv[1]);
	if (kill(data.pid, 0))
		print_error("Wrong PID!\n");
	data.str = argv[2];
	data.action.sa_flags = SA_SIGINFO;
	data.action.sa_sigaction = client_handler;
	sigemptyset(&data.action.sa_mask);
	sigaddset(&data.action.sa_mask, SIGUSR1);
	sigaddset(&data.action.sa_mask, SIGINT);
	sigaddset(&data.action.sa_mask, SIGQUIT);
	if (sigaction(SIGUSR2, &data.action, NULL) == -1)
		print_error("Error in client sigaction.\n");
	send_string(data);
	while (1)
		sleep (6);
	return (0);
}
