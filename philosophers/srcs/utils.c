/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:13:06 by cpugnair          #+#    #+#             */
/*   Updated: 2023/08/27 15:23:59 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
** This function converts the initial portion of the string
** pointed to by nptr to int representation.
*/
int	ft_atoi(const char *nptr)
{
	int				i;
	int				sign;
	unsigned int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

/*
** This function compares the two strings s1 and s2.
** It returns an integer less than, equal to, or greater than zero.
*/
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
	{
		if (s1[i] == 0 || s2[i] == 0)
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

/*
** This function returns the current time.
*/
useconds_t	chrono(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/*
** This function pauses the thread for the provided time.
*/
int	pause_time(useconds_t time_in_ms)
{
	useconds_t	start_time;
	useconds_t	end_time;

	start_time = chrono();
	end_time = start_time;
	while ((end_time - start_time) < time_in_ms)
	{
		if (usleep(time_in_ms) == -1)
			return (-1);
		end_time = chrono();
	}
	return (0);
}

/*
** With an odd number of philosophers, after his first meal each philosopher
** thinks long enough to let both neighbours eat first, so nobody starves.
*/
useconds_t	think_time(t_philo *philo)
{
	useconds_t	last_meal;

	pthread_mutex_lock(&philo->mtx_last_meal);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->mtx_last_meal);
	if (last_meal == 0 || philo->common->nb_philos % 2 == 0
		|| philo->common->time_to_eat * 2 <= philo->common->time_to_sleep)
		return (0);
	return (philo->common->time_to_eat * 2 - philo->common->time_to_sleep);
}
