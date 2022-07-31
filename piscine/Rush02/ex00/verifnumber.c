/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:01:55 by acanavat          #+#    #+#             */
/*   Updated: 2022/07/31 15:30:06 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*parse_number(char *str)
{
	int		i;
	char	*nb;

	i = 0;
	nb = malloc(sizeof(char) * ft_str_len(str));
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			nb[i] = str[i];
		i++;
	}
	return (nb);
}
