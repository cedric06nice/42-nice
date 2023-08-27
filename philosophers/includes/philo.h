/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:13:24 by cpugnair          #+#    #+#             */
/*   Updated: 2023/08/26 22:27:11 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

typedef struct s_data
{
	int					nb_philos;
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	long				times_must_eat;
	useconds_t			start_time;
	long long			times_eaten;
	pthread_mutex_t		mtx_times_eaten;
	unsigned long long	stop;
	pthread_mutex_t		mtx_stop;
	pthread_mutex_t		mtx_print;
}						t_data;

typedef struct s_philo
{
	int					id;
	pthread_t			thread_id;
	useconds_t			last_meal;
	pthread_mutex_t		mtx_last_meal;
	t_data				*common;
	pthread_mutex_t		mtx_fork;
}						t_philo;

/* ft_lists */
t_list					*ft_lstnew(void *content);
t_list					*ft_lstlast(t_list *lst);
void					ft_lstadd_back(t_list **lst, t_list *new);
void					ft_lstdelone(t_list *lst, void (*del)(void *));
void					ft_lstclear(t_list **lst, void (*del)(void *));

/* philo */
void					*init_philo(t_list *all, int nb_philos);
int						exit_program(t_list *all, const char *str);

/* print */
void					print_log(t_list *all, const char *str, useconds_t sec);
int						print_usage(void);
int						print_error(const char *str);

/* utils */
int						ft_atoi(const char *nptr);
int						ft_strcmp(const char *s1, const char *s2);
useconds_t				chrono(void);
int						pause_time(useconds_t time_in_ms);

#endif
