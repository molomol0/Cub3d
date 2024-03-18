/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:16:28 by jdenis           #+#    #+#             */
/*   Updated: 2023/05/12 18:17:14 by jdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;

	slen = ft_strlen(s);
	while (s && slen > 0)
	{
		if (s[slen] == (char)c)
			return ((char *)s + slen);
		slen--;
	}
	if (s && s[slen] == (char)c)
		return ((char *)s + slen);
	return (NULL);
}
