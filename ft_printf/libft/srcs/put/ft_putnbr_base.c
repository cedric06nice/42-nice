/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:54:48 by cpugnair          #+#    #+#             */
/*   Updated: 2022/12/21 16:53:23 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <stdio.h>

static long	is_neg(long nbr, char *base)
{
	if (nbr == 0)
		write (1, &base[0], 1);
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	return (nbr);
}

static int	base_is_correct(char *base)
{
	int		i;
	char	c;

	c = '\0';
	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || c == base[i] || base[i] <= 32)
			return (0);
		c = base[i];
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	char	str[28];
	long	nbr_;

	nbr_ = (long) nbr;
	i = 0;
	if (base_is_correct(base))
	{
		if (nbr_ <= 0)
			nbr_ = is_neg(nbr_, base);
		while (nbr_ > 0)
		{
			str[i] = (base[nbr_ % ft_strlen(base)]);
			nbr_ /= ft_strlen(base);
			i++;
		}
		while (i > 0)
		{
			i--;
			write (1, &str[i], 1);
		}
	}
}
