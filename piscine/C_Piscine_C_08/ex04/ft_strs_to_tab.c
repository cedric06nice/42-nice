/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 06:26:35 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/27 15:47:27 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*t_sstr;
	int			i;

	i = 0;
	t_sstr = malloc(sizeof(t_stock_str) * (ac + 1));
	if (t_sstr == NULL)
		return (NULL);
	if (ac < 0)
		return (0);
	while (i < ac)
	{
		t_sstr[i].size = ft_strlen(av[i]);
		t_sstr[i].str = av[i];
		t_sstr[i].copy = malloc(sizeof(char) * (ft_strlen(av[i]) + 1));
		if (t_sstr[i].copy == 0)
			return (0);
		t_sstr[i].copy = ft_strcpy(t_sstr[i].copy, t_sstr[i].str);
		i++;
	}
	t_sstr[i].str = 0;
	return (t_sstr);
}
