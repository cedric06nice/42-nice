/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:45:23 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/19 08:59:47 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	start;
	int	end;
	int	temp;

	i = size / 2;
	start = 0;
	end = size - 1;
	temp = 0;
	while (i > 0)
	{
		temp = tab[start];
		tab[start] = tab[end];
		tab[end] = temp;
		i--;
		start++;
		end--;
	}
}
/*
int	main(void)
{
	int	i;
	int	var[10] = { 2, 46, 5, 89, 0, 15, 68, 94, 54 };

	i = 0;
	while (i < 10)
	{
		printf("[ %d ] ", var[i]);
		i++;
	}
	printf("\n");
	i = 0;
	ft_rev_int_tab(var, 10);
	while (i < 10)
	{
		printf("[ %d ] ", var[i]);
		i++;
	}
}
*/