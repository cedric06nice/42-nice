/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:08:08 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/17 11:58:06 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	j = size;
	while (j >= 0)
	{
	i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i + 1];
				tab[i + 1] = tab[i];
				tab[i] = temp;
			}
			i++;
		}
		j--;
	}	
}
// int main(void)
// {
// 	int	i;
// 	int	t[7] = { 151, 489, 15, 26, 7, 73, 645 };	
// 	printf("BEFORE ");
// 	for (i = 0 ; i < 7  ; i++)
// 		printf("[%d] ", t[i]);
// 	ft_sort_int_tab(t, 7);
// 	printf("\nAFTER  ");
// 	for (i = 0 ; i < 7  ; i++)
//         printf("[%d] ", t[i]);
// }