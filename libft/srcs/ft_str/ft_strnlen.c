/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:36:34 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/02 17:36:50 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *str, size_t max_len)
{
	size_t	len;

	len = 0;
	while (len < max_len && str[len] != '\0')
		len++;
	return (len);
}
