/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:32:09 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/24 19:05:41 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

int	check_add_up_value(int nb)
{
	if (nb == 0)
		return (1);
	return (nb + check_add_up_value(nb - 1));
}

int	check_line(int side1, int tab[], int side2)
{
	int	i;
	int	j;
	int	size1;
	int	size2;

	i = 1;
	size1 = 1;
	while (tab[i])
	{
		if (tab[i - 1] < tab[i])
			size1++;
		i++;
	}
	j = ft_tab_size(tab);
	size2 = 1;
	while (tab[i])
	{
		if (j > 0 && tab[j - 1] < tab[j])
			size2++;
		j--;
	}
	if (size1 == side1 && size2 == side2)
		return (1);
	else
		return (0);
}

void	fill_line(int tab_head[], int nb_side, int *tab[])
{
	int	x;
	int	y;
	int	i;

	(void)tab_head;
	x = 0;
	i = 1;
	while (x < nb_side)
	{
		y = 0;
		while (y < nb_side)
		{
			tab[y][x] = i;
			printf("tab[%d][%d] = %d\n", x, y, i);
			y++;
		}
		x++;
	}
}
/*
// check_line(tab_head[x], tab[y], tab_head[x + nb_side / 2]);
tab [0, 1, 2, 3, 
	4, 5, 6, 7, 
	8, 9, 10, 11,
	12, 13, 14, 15]
 
		[ 0 ]	[ 1 ]	[ 2 ]	[ 3 ]
[ 0 ]	[0][0] 	[1][0] 	[2][0] 	[3][0]
[ 1 ]	[0][1] 	[1][1] 	[2][1] 	[3][1]
[ 2 ]	[0][2] 	[1][2] 	[2][2] 	[3][2]
[ 3 ]	[0][3] 	[1][3] 	[2][3] 	[3][3]
*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_tab_values(int tab[], int max_size)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == 0 || tab[i] > max_size)
			return (0);
		i++;
	}
	return (1);
}
