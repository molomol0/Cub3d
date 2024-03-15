/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:37:17 by jdenis           #+#    #+#             */
/*   Updated: 2024/01/24 15:18:58 by jdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strbstr(char *str, char *bstr, size_t len_bstr)
{
	size_t	index;

	index = 0;
	while (str[index] && bstr[index] && index < len_bstr)
	{
		if (str[index] != bstr[index])
			return (false);
		index++;
	}
	return (true);
}
