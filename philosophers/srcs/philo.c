/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:17:00 by cpugnair          #+#    #+#             */
/*   Updated: 2023/08/27 15:16:17 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
** This function run all the different actions the philosophers must do.
*/
static void	philo_all(t_list *all, t_philo *philo, t_philo *philo_next)
{
	print_log(all, "is thinking", 0);
	pthread_mutex_lock(&philo->mtx_fork);
	print_log(all, "has taken a fork", 0);
	pthread_mutex_lock(&philo_next->mtx_fork);
	print_log(all, "has taken a fork", 0);
	pthread_mutex_lock(&philo->mtx_last_meal);
	philo->last_meal = chrono() - philo->common->start_time;
	pthread_mutex_unlock(&philo->mtx_last_meal);
	print_log(all, "is eating", philo->common->time_to_eat);
	pthread_mutex_unlock(&philo->mtx_fork);
	pthread_mutex_unlock(&philo_next->mtx_fork);
	print_log(all, "is sleeping", philo->common->time_to_sleep);
}

/*
** This function is run in each philosopher's thread.
*/
static void	*philo_thread(void *all)
{
	t_philo	*philo;
	t_philo	*philo_next;
	int		i;

	i = 0;
	philo = ((t_list *)all)->content;
	philo_next = ((t_list *)all)->next->content;
	pause_time(philo->id % 2 * 3);
	if (philo->common->nb_philos == 1)
	{
		print_log(all, "is thinking", 0);
		pthread_mutex_lock(&philo->mtx_fork);
		print_log(all, "has taken a fork", 0);
	}
	pthread_mutex_lock(&philo->common->mtx_stop);
	while (philo->id != philo_next->id && !philo->common->stop
		&& (philo->common->times_must_eat == -1 || i++
			< (philo->common->times_must_eat * philo->common->nb_philos)))
	{
		pthread_mutex_unlock(&philo->common->mtx_stop);
		philo_all(all, philo, philo_next);
		pthread_mutex_lock(&philo->common->mtx_stop);
	}
	pthread_mutex_unlock(&philo->common->mtx_stop);
	return (NULL);
}

/*
** This function checks if a philosopher is dead or if all the philosophers
** have eaten enough and then stops the program.
*/
static void	*death_thread(t_list *all, t_philo *p)
{
	long	eat_count;
	long	last_meal;

	while (6)
	{
		p = all->content;
		pthread_mutex_lock(&p->common->mtx_times_eaten);
		eat_count = p->common->times_eaten;
		pthread_mutex_unlock(&p->common->mtx_times_eaten);
		pthread_mutex_lock(&p->mtx_last_meal);
		last_meal = p->last_meal;
		pthread_mutex_unlock(&p->mtx_last_meal);
		if (chrono() - p->common->start_time
			- last_meal >= p->common->time_to_die
			|| eat_count == p->common->nb_philos * p->common->times_must_eat)
		{
			pthread_mutex_lock(&p->common->mtx_stop);
			p->common->stop = 1;
			pthread_mutex_unlock(&p->common->mtx_stop);
			if (eat_count != p->common->nb_philos * p->common->times_must_eat)
				print_log(all, "died", 0);
			return (NULL);
		}
		all = all->next;
	}
}

/*
** This function creates a thread for each philosopher.
*/
void	*init_philo(t_list *all_philos, int nb_philos)
{
	int		i;
	t_list	*head;
	t_philo	*philo;

	i = 0;
	head = all_philos;
	while (i < nb_philos)
	{
		philo = head->content;
		if (pthread_create(&philo->thread_id, NULL, philo_thread, head))
			return (0);
		head = head->next;
		i++;
	}
	death_thread(all_philos, NULL);
	i = 0;
	while (i < nb_philos)
	{
		philo = head->content;
		pthread_join(philo->thread_id, NULL);
		head = head->next;
		i++;
	}
	return (NULL);
}

/*
** This function frees the memory and prints an error message if provided.
*/
int	exit_program(t_list *all, const char *str)
{
	t_philo	*p;
	t_list	*tmp;

	tmp = all;
	while (all)
	{
		p = all->content;
		if (p->id == p->common->nb_philos)
			all->next = NULL;
		all = all->next;
	}
	ft_lstclear(&tmp, free);
	if (str)
		print_error(str);
	return (0);
}
