/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbersplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:21:59 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/07/31 18:14:48 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	**execute(char *number, char **t)
{
	int	x;
	int	i;
	int	count;

	i = 2;
	x = 0;
	count = ft_str_len(number);
	while (count > 0)
	{
		i = 2;
		t[x] = (char *) malloc(sizeof(char) * 3);
		while (i >= 0)
		{
			if (count < 1)
				t[x][i--] = '0';
			else
			{
				t[x][i] = number[--count];
				i--;
			}
		}
		i = 2;
		x++;
	}
	t[x] = 0;
	return (t);
}

char	**numbersplit(char *number)
{
	char	**t;

	if (!number)
		return (0);
	t = (char **) malloc(sizeof(char *)
			* ((ft_str_len(number) / 3) + 2));
	t = execute(number, t);
	return (t);
}
/*
int	main(void)
{
	char	*number = "73642801293";
	char	**f;
	int		x;
	int		y;

	y = 0;
	x = 0;
	f = numbersplit(number);
	while (f[x])
	{
		while (y <= 2)
		{
			printf("%c", f[x][y]);
			y++;
		}
		printf("\n");
		y = 0;
		x++;
	}
	return (0);
}
*/