/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:00:31 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/24 19:00:49 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

int	main(int argc, char *argv[])
{
	int	tab_size;
	int	tab_head[82];
	int	nb_side;

	if (argc != 2)
		return (write_error());
	if (ft_strlen(argv[1]) > 161)
		return (write_error());
	ft_atoi(tab_head, argv[1]);
	tab_size = ft_tab_size(tab_head);
	nb_side = ft_sqrt(tab_size);
	if (nb_side == 0)
		return (write_error());
	if (check_tab_values(tab_head, nb_side) == 0)
		return (write_error());
	return (0);
}
