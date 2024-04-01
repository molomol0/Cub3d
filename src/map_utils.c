/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:37:12 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/01 01:33:46 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "libft.h"

int	only_wall(char *line)
{
	int	index;

	index = 0;
	if (line[0] == '\0')
		return (0);
	while (line[index])
	{
		if (line[index] != '1' && line[index] != ' ' && line[index] != '0')
			return (0);
		index++;
	}
	return (1);
}

int	other_char(char *line)
{
	int	index;

	index = 0;
	while (line[index])
	{
		if (line[index] != '1' && line[index] != '0' && line[index] != ' '
			&& line[index] != 'N' && line[index] != 'S' && line[index] != 'W'
			&& line[index] != 'E' && line[index] != '3')
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strappen(char *s1, char const *s2)
{
	size_t	size;
	size_t	index;
	char	*str;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(size);
	index = 0;
	if (str == NULL)
		return (NULL);
	while (index < ft_strlen(s1))
	{
		str[index] = s1[index];
		index++;
	}
	str[index] = '\0';
	ft_strlcat(str, s2, size);
	if (s1 != NULL)
		free(s1);
	return (str);
}
