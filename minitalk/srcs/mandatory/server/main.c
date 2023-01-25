/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:43:39 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/25 10:03:03 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minitalk.h"

int		main(void)
{
	t_data	data;

	data.pid = getpid();
	data.str = NULL;
	data.i = 0;
	data.j = 0;
	ft_printf("Server PID: %d\n", data.pid);
}
