/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:01:55 by acanavat          #+#    #+#             */
/*   Updated: 2022/07/30 15:10:02 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	parse_number(char *str)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			nb = nb * 10 + str[i] - 48;
		}
		else
		{
			return (-1);
		}
		i++;
	}
	return (nb);
}
