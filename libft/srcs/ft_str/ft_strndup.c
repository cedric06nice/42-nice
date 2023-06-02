/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:29:00 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/02 17:38:06 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t	len;
	char	*new_str;

	len = ft_strnlen(str, n);
	new_str = malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strncpy(new_str, str, len);
	new_str[len] = '\0';
	return (new_str);
}
