/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:07:26 by cpugnair          #+#    #+#             */
/*   Updated: 2022/11/19 23:04:34 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** The ft_putchar_fd() function write the character 'c' on the given file.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
