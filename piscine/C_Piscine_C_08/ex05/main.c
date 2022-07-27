/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 06:53:29 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/27 11:02:45 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>

int	ft_strlen(char *str)
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

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*t_sstr;
	int			i;

	i = 0;
	t_sstr = malloc(sizeof(t_stock_str) * (ac + 1));
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

int	main(int argc, char **argv)
{
	t_stock_str	*s_str;

	s_str = ft_strs_to_tab(argc, argv);
	ft_show_tab(s_str);
	return (0);
}
