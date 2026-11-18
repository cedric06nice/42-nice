/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:36:49 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/28 11:13:28 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putchar(char c);
void	ft_swap(int *a, int *b);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

int	main(void)
{
	int	a;
	int	b;

	a = 1;
	b = 2;
	ft_putchar('a');
	printf(" <= ft_putchar");
	printf("\n");
	ft_swap(&a, &b);
	printf("ft_swap = (a = 1, b = 2) => (a = %d, b = %d)\n", a, b);
	ft_putstr("ft_putstr = Hello World!\n");
	printf("ft_strlen = %d\n", ft_strlen("Hello World!"));
	printf("ft_strcmp = %d\n", ft_strcmp("Hello World!", "Hello World!"));
	return (0);
}
