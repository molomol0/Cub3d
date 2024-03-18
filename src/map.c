/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:20:16 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/18 17:23:53 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "libft.h"

static int	only_wall(char *line)
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
		if (line[index] != '1' && line[index] != '0' &&
			line[index] != ' ' && line[index] != 'N' &&
			line[index] != 'S' && line[index] != 'W' &&
			line[index] != 'E')
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

void	put_map(char *line, t_cub *cub, int fd)
{
	char *joined_map;

	if (only_wall(line) == 1)
	{
		joined_map = malloc(1);
		joined_map[0] = 0;
		while (line)
		{
			if (other_char(line) == 1)
			{
				ft_putstr_fd("Error\nInvalid map\n", 2);
				free(joined_map);
				while (line)
				{
					free(line);
					line = get_next_line(fd);
					delete_newline(&line);
				}
				free_data(cub);
				exit(1);
			}
			line = ft_strappen(line, "\n");
			joined_map = ft_strappen(joined_map, line);
			if (!joined_map)
			{
				ft_putstr_fd("Error\nMalloc failed\n", 2);
				while (line)
				{
					free(line);
					line = get_next_line(fd);
					delete_newline(&line);
				}
				free_data(cub);
				exit(1);
			}
			if (line != NULL)
				free(line);
			line = get_next_line(fd);
			delete_newline(&line);
		}
		cub->map = ft_split(joined_map, '\n');
		free(joined_map);
		if (!cub->map)
		{
			ft_putstr_fd("Error\nMalloc failed\n", 2);
			free_data(cub);
			exit(1);
		}
	}
	
}