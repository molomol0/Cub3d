/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_utils_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:51:53 by jdenis           #+#    #+#             */
/*   Updated: 2024/03/15 18:08:56 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*extract_token(char *str_to_tokenize, size_t token_size)
{
	char	*token;
	size_t	index;

	index = 0;
	token = malloc(sizeof(char) * (token_size + 1));
	if (!token)
		return (NULL);
	while (index < token_size)
	{
		token[index] = str_to_tokenize[index];
		index++;
	}
	token[index] = '\0';
	return (token);
}
