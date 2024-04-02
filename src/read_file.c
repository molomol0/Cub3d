/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:12:38 by ftholoza          #+#    #+#             */
/*   Updated: 2024/04/02 19:43:23 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"

void	put_texture(char *line, char *texture, char **direction, t_cub *cub)
{
	if (ft_strncmp(line, texture, ft_strlen(texture)) == 0)
	{
		if (*direction == NULL)
		{
			*direction = ft_strdup(line + skip_space(line, texture));
			if (!*direction)
			{
				print_err("Error\nMalloc failed\n");
				free_data(cub);
				exit(1);
			}
			if (texture_valid(*direction) == -1)
				exit_map(cub, line, NULL);
			delete_point_texture(direction);
		}
		else
			print_duplicate(texture, "texture", cub, line);
	}
}

void	put_ceiling_floor(char *line, char *cf, int *color, t_cub *cub)
{
	int	first_coma;
	int	second_coma;

	first_coma = 0;
	second_coma = 0;
	if (ft_strncmp(line, cf, ft_strlen(cf)) == 0)
	{
		if (color[0] == -1)
		{
			get_comas(line, &first_coma, &second_coma);
			color[0] = ft_atoi(line + skip_space(line, cf));
			color[1] = ft_atoi(line + first_coma + 1);
			color[2] = ft_atoi(line + second_coma + 1);
			valid_color(color, cub, line);
		}
		else
			print_duplicate(cf, "color", cub, line);
	}
}

void	unknown_line(char *line, t_cub *cub)
{
	if (line[0] != '\0')
	{
		ft_putstr_fd("Error\nUnknown line\n", 2);
		free_data(cub);
		exit(1);
	}
}

void	assign_data(char *line, t_cub *cub)
{
	if (check_line_ok(line) == -1)
	{
		exit_map(cub, line, "Error\nInvalid line\n");
	}
	put_texture(line, "NO ", &cub->texture->no, cub);
	put_texture(line, "SO ", &cub->texture->so, cub);
	put_texture(line, "WE ", &cub->texture->we, cub);
	put_texture(line, "EA ", &cub->texture->ea, cub);
	put_ceiling_floor(line, "F ", cub->floor, cub);
	put_ceiling_floor(line, "C ", cub->ceiling, cub);
	put_map(line, cub);
}

int	travel_file(char *file, t_cub *cub)
{
	char	*line;

	if ((ft_strlen(file) <= 4) || ft_strncmp(file + ft_strlen(file) - 4, ".cub",
			4) != 0)
		return (print_err("Error\nInvalid file extension\n"));
	cub->tmp = open(file, O_RDONLY);
	if (cub->tmp == -1)
		return (print_err("Error\nCannot open file\n"));
	line = get_next_line(cub->tmp);
	delete_newline(&line);
	while (line)
	{
		assign_data(line, cub);
		if (cub->map != NULL)
			break ;
		if (line != NULL)
		{
			free(line);
			line = get_next_line(cub->tmp);
			delete_newline(&line);
		}
	}
	get_gun_img(cub);
	close(cub->tmp);
	return (0);
}
