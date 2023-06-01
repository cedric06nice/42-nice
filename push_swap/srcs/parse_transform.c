/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:06:41 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/21 02:48:10 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Check if there are duplicates in the list of numbers
*/
static int	check_duplicates(int *arr, int num)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == num)
			return (1);
		i++;
	}
	return (0);
}

static int	count_j(char **arg, int i, int j)
{
	if (j == 0
		&& (ft_isdigit(arg[i][j])
		|| ((arg[i][j] == '-' || arg[i][j] == '+')
				&& ft_isdigit(arg[i][j + 1]))))
		return (j + 1);
	else if (ft_isdigit(arg[i][j]))
		return (j + 1);
	else
		return (-1);
}

/*
** Transform arguments into list of numbers
*/
int	*transform_args(char **arguments, int i, int count_args)
{
	int		*list_num;
	int		j;
	int		k;
	int		num;

	list_num = malloc(sizeof(int) * count_args);
	k = 0;
	while (arguments[i])
	{
		j = 0;
		while (arguments[i][j])
		{
			if (count_j(arguments, i, j) == -1)
				return (NULL);
			j = count_j(arguments, i, j);
		}
		num = ps_atoi(arguments[i]);
		if (num >= INT_MAX || num <= INT_MIN)
			return (NULL);
		list_num[k++] = num;
		i++;
	}
	check_duplicates(list_num, 1);
	return (list_num);
}
