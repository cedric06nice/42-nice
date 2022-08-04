/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_breaks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:03:53 by elombard          #+#    #+#             */
/*   Updated: 2022/08/03 18:13:32 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
**	Check if there is as many '\n' as lines in the file.
*/
int	check_line_breaks(char *str, char **board)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	x;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			j++;
		i++;
	}
	x = 0;
	while (board[x] != 0)
		x++;
	return (j == x);
}
