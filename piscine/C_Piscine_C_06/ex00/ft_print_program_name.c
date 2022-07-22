/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:44:28 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/22 11:44:30 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc != 1)
		return (1);
	while (*(argv[0] + i))
	{
		write(1, argv[0] + i, 1);
		i++;
	}
	write(1, '\n', 1);
}
