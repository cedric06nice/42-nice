/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:52:03 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/24 18:59:47 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

int	ft_is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(int *tab, char str[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (i % 2 == 0 && ft_is_number(str[i]) == 1)
		{
			tab[j] = str[i] - '0';
			j++;
		}
		if (i % 2 == 1 && ft_is_space(str[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_tab_size(int tab[])
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
		i++;
	if (i * i != nb)
		return (0);
	return (i);
}
