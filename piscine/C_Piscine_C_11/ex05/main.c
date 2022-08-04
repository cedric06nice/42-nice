/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:38:16 by cpugnair          #+#    #+#             */
/*   Updated: 2022/08/04 17:44:23 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
	{
		if (s1[i] == 0 || s2[i] == 0)
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_args_check(char **argv, int (*calc[5])(int, int))
{
	if (argv[2][0] == '+')
		ft_putnbr(calc[0](ft_atoi(argv[1]), ft_atoi(argv[3])));
	else if (argv[2][0] == '-')
		ft_putnbr(calc[1](ft_atoi(argv[1]), ft_atoi(argv[3])));
	else if (argv[2][0] == '*')
		ft_putnbr(calc[2](ft_atoi(argv[1]), ft_atoi(argv[3])));
	else if (argv[2][0] == '/')
	{
		if (ft_atoi(argv[3]) == 0)
			ft_putstr("Stop : division by zero");
		else
			ft_putnbr(calc[3](ft_atoi(argv[1]), ft_atoi(argv[3])));
	}
	else if (argv[2][0] == '%')
	{
		if (ft_atoi(argv[3]) == 0)
			ft_putstr("Stop : modulo by zero");
		else
			ft_putnbr(calc[4](ft_atoi(argv[1]), ft_atoi(argv[3])));
	}
	else
		ft_putnbr(0);
}

int	main(int argc, char **argv)
{
	int	(*calc[5])(int, int);

	calc[0] = &ft_add;
	calc[1] = &ft_sub;
	calc[2] = &ft_mul;
	calc[3] = &ft_div;
	calc[4] = &ft_mod;
	if (argc != 4)
		return (0);
	if (argc == 4)
	{
		ft_args_check(argv, calc);
	}
	write(1, "\n", 1);
	return (0);
}
