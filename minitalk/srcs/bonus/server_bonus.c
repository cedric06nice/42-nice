/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:43:39 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/29 11:38:40 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	server_handler(int signum, siginfo_t *siginfo, void *uap)
{
	static int	ascii_num = 0;
	static int	byte = 0;

	(void)uap;
	if (signum == SIGUSR1)
		ascii_num += (128 >> byte);
	byte += 1;
	if (byte == 8)
	{
		ft_putchar_fd(ascii_num, 1);
		byte = 0;
		ascii_num = 0;
	}
	if (siginfo->si_pid == 0)
		print_error("Server didn't get client's PID.\n");
	if (kill(siginfo->si_pid, SIGUSR2) == -1)
		print_error("Error in returning signal!\n");
}

int	main(void)
{
	t_data		data;

	write(1, "Server started!\nPID: ", 21);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sigemptyset(&data.action.sa_mask);
	data.action.sa_flags = SA_SIGINFO;
	data.action.sa_sigaction = server_handler;
	sigaction(SIGUSR1, &data.action, 0);
	sigaction(SIGUSR2, &data.action, 0);
	while (1)
		pause();
	return (0);
}
