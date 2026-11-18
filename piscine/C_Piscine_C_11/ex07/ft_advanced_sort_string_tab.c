/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:18:53 by cpugnair          #+#    #+#             */
/*   Updated: 2022/08/05 08:20:35 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int i;
	int a;
	char *tmp;

	a = 0;
	while (a == 0)
	{
		a = 1;
		i = -1;
		while (tab[++i + 1])
		{
			if ((*cmp)(tab[i], tab[i + 1]) > 0)
			{
				a = 0;
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
		}
	}
}