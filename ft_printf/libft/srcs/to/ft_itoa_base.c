/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:53:33 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/03 09:57:45 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <stdio.h>

char	*ft_itoa_base(unsigned int n, char *base)
{
	char			*str;
	unsigned int	i;
	char			*div;
	char			*mod;

	i = ft_strlen(base);
	str = (char *)malloc(sizeof(char));
	if (!str)
		return (NULL);
	if (n >= i)
	{
		div = ft_itoa_base(n / i, base);
		mod = ft_itoa_base(n % i, base);
		str = ft_strjoin(div, mod);
		free(div);
		free(mod);
	}
	else if (n < i)
		str[0] = base[n];
	return (str);
}
