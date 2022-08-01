/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numberprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:47:45 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/07/31 18:26:04 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	premierchiffre(char str, t_dict *number)
{
	int	i;
	int	e;
	int	e2;

	i = -1;
	while (&number[++i])
	{
		if (str == number[i].id[0])
		{
			ft_putstr(number[i].word);
			e = 1;
		}
	}
	i = 0;
	while (&number[i])
	{
		if (ft_strcmp(number[i].id, "100") == 0)
		{
			ft_putstr(number[i].word);
			e2 = 1;
		}
	}
	if (e != 1 && e2 != 1)
		print_dict_error();
}

void	deuxiemechiffre(char str, t_dict *number)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	while (&number[i])
	{
		if (str == number[i].id[0])
		{
			ft_putstr(number[i].word);
			e++;
		}
		i++;
	}
	if (e != 1)
		print_dict_error();
}

void	troisiemechiffre(char str, t_dict *number)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	while (&number[i])
	{
		if (str == number[i].id[0])
		{
			ft_putstr(number[i].word);
			e++;
		}
		i++;
	}
	if (e != 1)
		print_dict_error();
}

void	exception(char str, t_dict *number)
{
	int	i;
	int	e;

	e = 0;
	i = 0;
	while (&number[i])
	{
		if (str == number[i].id[1])
		{
			ft_putstr(number[i].word);
			e++;
		}
	}
	if (e != 1)
		print_dict_error();
}

void	numberprint(char *str, t_dict *struct_dict)
{
	// int	i;
	// int	cas;

	// i = 0;
	// cas = 0;
	if (str[0] > 48)
		premierchiffre(str[0], struct_dict);
	if (str[1] > 48)
	{
		if (str[1] > 50)
			deuxiemechiffre(str[1], struct_dict);
		if (str[1] == 49)
			exception(str[2], struct_dict);
	}
	if (str[2] > 48 && str[1] > 49)
		troisiemechiffre(str[2], struct_dict);
}
