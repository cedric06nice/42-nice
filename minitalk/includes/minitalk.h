/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:44:44 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/25 08:47:26 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

typedef struct s_data
{
	int			pid;
	char		*str;
	int			i;
	int			j;
}				t_data;

#endif
