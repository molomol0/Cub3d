/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:49:17 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/02 19:43:26 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"

int	check_line_ok(char *line)
{
	if (line[0] == '\0')
		return (0);
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0)
		return (0);
	if (ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
		return (0);
	if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		return (0);
	if (only_wall(line) == 1)
		return (0);
	return (-1);
}

void	check_sprite(t_cub *cub, char *sprite)
{
	int	fd;

	fd = open(sprite, O_RDONLY);
	if (!sprite || fd == -1)
	{
		ft_putstr_fd("Error\nSprite\n", 2);
		free_data(cub);
		exit(1);
	}
	close(fd);
}

void	get_gun_img(t_cub *cub)
{
	cub->texture->pi = ft_strdup("/texture/gun.xpm");
	check_sprite(cub, cub->texture->pi + 1);
	cub->texture->pif = ft_strdup("/texture/feu.xpm");
	check_sprite(cub, cub->texture->pif + 1);
	cub->texture->pir1 = ft_strdup("/texture/recul1.xpm");
	check_sprite(cub, cub->texture->pir1 + 1);
	cub->texture->pir2 = ft_strdup("/texture/recul2.xpm");
	check_sprite(cub, cub->texture->pir2 + 1);
	cub->texture->door = ft_strdup("/texture/door.xpm");
	check_sprite(cub, cub->texture->door + 1);
}

void	delete_point_texture(char **direction)
{
	char	*temp;

	if (*direction != NULL && **direction != '\0')
	{
		temp = *direction;
		while (*temp != '\0')
		{
			*temp = *(temp + 1);
			temp++;
		}
	}
}

void	get_comas(char *line, int *first_coma, int *second_coma)
{
	int	start;

	start = 0;
	while (line[start])
	{
		if (line[start] == ',')
		{
			if (*first_coma)
				*second_coma = start;
			else
				*first_coma = start;
		}
		start++;
	}
}
