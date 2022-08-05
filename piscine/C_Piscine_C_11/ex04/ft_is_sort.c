/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:31:58 by cpugnair          #+#    #+#             */
/*   Updated: 2022/08/05 08:16:23 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int a;
	int b;
	int i;

	a = 0;
	b = 0;
	i = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) >= 0)
			a++;
		if ((*f)(tab[i], tab[i + 1]) <= 0)
			b++;
		i++;
	}
	if (a == i || b == i)
		return (1);
	return (0);
}
