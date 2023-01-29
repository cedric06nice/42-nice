/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:44:44 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/29 10:09:32 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <signal.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

typedef struct s_data
{
	pid_t				pid;
	struct sigaction	action;
	char				*str;
}						t_data;

int						print_error(char *error);

#endif
