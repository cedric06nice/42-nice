/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:54:28 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/21 15:44:05 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_swap(char *a, char *b)
{
	char	temp[] = *a;
	
	*a = *b;
	*b = temp;
}

int	main(int argc, char *argv[])
{
	int	i;
	char	temp[] = { "" };

	if (argc < 2)
		return (1);
	i = argc;
	while (i > 1)
	{
		i--;
		ft_putstr(argv[i]);
		write(1, "\n", 1);
	}
	i = argc;
	while (i > 1)
	{
		i--;
		ft_putstr(argv[i]);
		write(1, "\n", 1);
	}
	return (0);
}
