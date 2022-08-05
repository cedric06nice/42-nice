/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:09:16 by cpugnair          #+#    #+#             */
/*   Updated: 2022/08/05 08:16:30 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
	{
		if (s1[i] == 0 || s2[i] == 0)
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

void ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				a = 0;
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
		}
	}
}
