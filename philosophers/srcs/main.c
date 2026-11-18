/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:12:03 by cpugnair          #+#    #+#             */
/*   Updated: 2023/08/27 15:06:20 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
** Every argument must be a plain positive integer that fits in an int:
** digits only (an optional leading '+'), no sign, letters or spaces.
*/
static int	valid_arguments(int argc, char **argv)
{
	char	*digits;
	int		len;

	while (--argc > 0)
	{
		digits = argv[argc];
		if (*digits == '+')
			digits++;
		len = 0;
		while (digits[len] >= '0' && digits[len] <= '9')
			len++;
		if (len == 0 || digits[len] != '\0' || len > 10
			|| (len == 10 && ft_strcmp(digits, "2147483647") > 0))
			return (0);
	}
	return (1);
}

/*
** This function parses the arguments passed to the program.
** If argument 5 is not passed, it is set to -1.
*/
static t_data	parse_arguments(char **argv)
{
	t_data	data;

	data.nb_philos = ft_atoi(argv[1]);
	data.time_to_die = ft_atoi(argv[2]);
	data.time_to_eat = ft_atoi(argv[3]);
	data.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data.times_must_eat = ft_atoi(argv[5]);
	else
		data.times_must_eat = -1;
	return (data);
}

/*
** This function creates a list of philosophers.
*/
static t_list	*create_philo_list(t_data *data)
{
	t_list	*all_philos;
	t_philo	*philo;
	int		i;

	all_philos = NULL;
	i = 0;
	while (i < data->nb_philos)
	{
		philo = malloc(sizeof(t_philo));
		if (!philo)
		{
			exit_program(NULL, "malloc failed");
			return (NULL);
		}
		philo->id = i + 1;
		philo->thread_id = 0;
		philo->last_meal = 0;
		philo->common = data;
		pthread_mutex_init(&philo->mtx_last_meal, NULL);
		pthread_mutex_init(&philo->mtx_fork, NULL);
		ft_lstadd_back(&all_philos, ft_lstnew(philo));
		i++;
	}
	return (all_philos);
}

int	main(int argc, char **argv)
{
	t_list	*all_philos;
	t_data	data;

	if (argc < 5 || argc > 6)
		return (print_usage());
	if (!valid_arguments(argc, argv))
		return (print_error("arguments must be positive integers"));
	data = parse_arguments(argv);
	if (data.nb_philos <= 0 || data.time_to_die <= 0
		|| data.time_to_eat <= 0 || data.time_to_sleep <= 0
		|| data.times_must_eat == 0)
		return (print_error("these numbers are not allowed"));
	if (data.nb_philos > 200)
		return (print_error("no more than 200 philosophers"));
	data.stop = 0;
	data.times_eaten = 0;
	data.start_time = chrono();
	pthread_mutex_init(&data.mtx_times_eaten, NULL);
	pthread_mutex_init(&data.mtx_stop, NULL);
	pthread_mutex_init(&data.mtx_print, NULL);
	all_philos = create_philo_list(&data);
	ft_lstlast(all_philos)->next = all_philos;
	init_philo(all_philos, data.nb_philos);
	exit_program(all_philos, NULL);
	return (0);
}
