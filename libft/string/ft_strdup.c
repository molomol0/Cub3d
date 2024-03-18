/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:48:50 by jdenis           #+#    #+#             */
/*   Updated: 2024/01/17 13:14:30 by jdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	index;
	char	*strdup;

	if (!str)
		return (NULL);
	strdup = malloc(ft_strlen(str) + 1);
	if (!strdup)
		return (NULL);
	index = 0;
	while (str[index])
	{
		strdup[index] = str[index];
		index++;
	}
	strdup[index] = '\0';
	return (strdup);
}
