/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 06:26:35 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/27 06:52:26 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int			i;
	char		*a;

	i = 0;
	a = malloc(sizeof(char) * (ft_strlen(src)));
	while (src[i])
	{
		a[i] = src[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*t_sstr;
	int			i;

	i = 0;
	t_sstr = malloc(sizeof(t_stock_str) * ac + 1);
	if (t_sstr == NULL)
		return (NULL);
	while (i < ac)
	{
		t_sstr[i].size = ft_strlen(av[i]);
		t_sstr[i].str = av[i];
		t_sstr[i].copy = ft_strdup(av[i]);
		i++;
	}
	t_sstr[i].str = 0;
	return (t_sstr);
}