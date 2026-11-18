/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:32:24 by cpugnair          #+#    #+#             */
/*   Updated: 2023/09/07 21:02:29 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
** This function prints one log line, in the subject's format:
** "<timestamp_in_ms> <philosopher_number> <action>".
*/
static void	print_terminal(useconds_t time, t_philo *philo, const char *str)
{
	pthread_mutex_lock(&philo->common->mtx_print);
	printf("%u %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->common->mtx_print);
}

/*
** This function sends the meaaasge to print in the terminal,
** pauses the thread if required and increeases the number of times eaten.
*/
void	print_log(t_list *all, const char *str, useconds_t sec)
{
	t_philo		*philo;
	useconds_t	elapsed_time;
	int			stop;
	long		e;

	philo = all->content;
	pthread_mutex_lock(&philo->common->mtx_stop);
	stop = philo->common->stop;
	pthread_mutex_unlock(&philo->common->mtx_stop);
	pthread_mutex_lock(&philo->common->mtx_times_eaten);
	e = philo->common->times_eaten;
	pthread_mutex_unlock(&philo->common->mtx_times_eaten);
	elapsed_time = chrono() - philo->common->start_time;
	if (!eat_enough(e, philo->common->nb_philos, philo->common->times_must_eat)
		&& (!stop || !ft_strcmp(str, "died")))
		print_terminal(elapsed_time, philo, str);
	if (!eat_enough(e, philo->common->nb_philos, philo->common->times_must_eat)
		&& (!stop || !ft_strcmp(str, "died")))
		pause_time(sec);
	if (ft_strcmp(str, "is eating") == 0)
	{
		pthread_mutex_lock(&philo->common->mtx_times_eaten);
		philo->common->times_eaten++;
		pthread_mutex_unlock(&philo->common->mtx_times_eaten);
	}
}

/*
** This function prints the usage of the program.
*/
int	print_usage(void)
{
	printf("\033[0;31mError:\033[0m Wrong number of arguments\n");
	printf("\033[0;32mUsage:\033[0m ./philo \
<number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat]\n");
	return (1);
}

/*
** This function prints an error message.
*/
int	print_error(const char *str)
{
	printf("\033[0;31mError: \033[0m%s\n", str);
	return (1);
}
