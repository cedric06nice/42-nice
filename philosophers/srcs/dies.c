/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dies.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:25:48 by cpugnair          #+#    #+#             */
/*   Updated: 2023/09/07 20:58:30 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	eat_enough(long eaten, long nb_philos, long must_eat)
{
	if (must_eat == -1)
		return (0);
	if (eaten >= nb_philos * must_eat)
		return (1);
	return (0);
}

void	end_dies(t_list *all, t_philo *p, long eaten)
{
	if (eat_enough(eaten, p->common->nb_philos, p->common->times_must_eat) == 1)
	{
		if (p->common->times_must_eat == 1)
		{
			pause_time(50);
			printf("All philosophers ate once\n");
		}
		else if (p->common->times_must_eat == 2)
		{
			pause_time(50);
			printf("All philosophers ate twice\n");
		}
		else
		{
			pause_time(50);
			printf("All philosophers ate %ld times\n",
				p->common->times_must_eat);
		}
	}
	else
		print_log(all, "died", 0);
}
