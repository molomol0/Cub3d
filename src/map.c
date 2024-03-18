/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:20:16 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/18 17:37:47 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "libft.h"

void	exit_map(t_cub *cub, char *line, int fd, char *str)
{
	ft_putstr_fd(str, 2);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		delete_newline(&line);
	}
	free_data(cub);
	exit(1);
}

void	split_map(t_cub *cub, char *joined_map)
{
	cub->map = ft_split(joined_map, '\n');
	free(joined_map);
	if (!cub->map)
	{
		ft_putstr_fd("Error\nMalloc failed\n", 2);
		free_data(cub);
		exit(1);
	}
}

void	put_map(char *line, t_cub *cub, int fd)
{
	char	*joined_map;

	if (only_wall(line) == 1)
	{
		joined_map = malloc(1);
		joined_map[0] = 0;
		while (line)
		{
			if (other_char(line) == 1)
			{
				free(joined_map);
				exit_map(cub, line, fd, "Error\nInvalid map\n");
			}
			line = ft_strappen(line, "\n");
			joined_map = ft_strappen(joined_map, line);
			if (!joined_map)
				exit_map(cub, line, fd, "Error\nMalloc failed\n");
			if (line != NULL)
				free(line);
			line = get_next_line(fd);
			delete_newline(&line);
		}
		split_map(cub, joined_map);
	}
}
