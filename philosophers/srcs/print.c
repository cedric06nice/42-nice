/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:32:24 by cpugnair          #+#    #+#             */
/*   Updated: 2023/08/27 15:21:20 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
** This function returns the color by Philosoher's id
** to diferenciate them in the terminal.
*/
static char	*print_color(int color)
{
	if (color % 7 == 1)
		return ("\033[0;31m");
	else if (color % 7 == 2)
		return ("\033[0;32m");
	else if (color % 7 == 3)
		return ("\033[0;33m");
	else if (color % 7 == 4)
		return ("\033[0;34m");
	else if (color % 7 == 5)
		return ("\033[0;35m");
	else if (color % 7 == 6)
		return ("\033[0;36m");
	else
		return ("\033[0;37m");
}

/*
** This function prints safely the log in the terminal in color.
*/
static void	print_terminal(useconds_t time, t_philo *philo, const char *str)
{
	pthread_mutex_lock(&philo->common->mtx_print);
	printf("%s%08u %03d %s\033[0m\n", print_color(philo->id), time, philo->id,
		str);
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
	long		times_eaten;

	philo = all->content;
	pthread_mutex_lock(&philo->common->mtx_stop);
	stop = philo->common->stop;
	pthread_mutex_unlock(&philo->common->mtx_stop);
	pthread_mutex_lock(&philo->common->mtx_times_eaten);
	times_eaten = philo->common->times_eaten;
	pthread_mutex_unlock(&philo->common->mtx_times_eaten);
	elapsed_time = chrono() - philo->common->start_time;
	if (philo->common->nb_philos * philo->common->times_must_eat != times_eaten
		&& (!stop || ft_strcmp(str, "died") == 0))
		print_terminal(elapsed_time, philo, str);
	if (philo->common->nb_philos * philo->common->times_must_eat != times_eaten
		&& (!stop || ft_strcmp(str, "died") == 0))
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
