/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:12:38 by ftholoza          #+#    #+#             */
/*   Updated: 2024/03/18 17:19:56 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_struct.h"
#include "cub.h"

void	print_duplicate(char *duplicated, char *type, t_cub *cub, char *line, int fd)
{
	ft_putstr_fd("Error\nDuplicate ", 2);
	ft_putstr_fd(duplicated, 2);
	ft_putstr_fd(type, 2);
	ft_putstr_fd("\n", 2);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		delete_newline(&line);
	}
	free_data(cub);
	exit(1);
}

int	print_err(char *str)
{
	ft_putstr_fd(str, 2);
	return (-1);
}

int		skip_space(char *line, char *id)
{
	int	index;

	index = ft_strlen(id);
	while ((line[index] >= '\t' && line[index] <= '\r') || line[index] == ' ')
		index++;
	return (index);
}

void	put_texture(char *line, char *texture, char **direction, t_cub *cub, int fd)
{
	if (ft_strncmp(line, texture, ft_strlen(texture)) == 0)
	{
		if (*direction == NULL)
			*direction = ft_strdup(line + skip_space(line, texture));	
		else
			print_duplicate(texture, "texture", cub, line, fd);
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

void	valid_color(int *color, t_cub *cub, char *line)
{
	int	index;

	index = 1;
	while (line[index])
	{
		if (ft_isdigit(line[index]) || line[index] == ' ' || line[index] == ',')
			index++;
		else
		{
			printf("line[%d] = %c\n", index, line[index]);
			ft_putstr_fd("Error\nColor should be in RGB format\n", 2);
			free(line);
			free_data(cub);
			exit(1);
		}
	}
	if (color[0] < 0 || color[1] < 0 || color[2] < 0
		|| color[0] > 255 || color[1] > 255 || color[2] > 255)
	{
		ft_putstr_fd("Error\nInvalid color\n", 2);
		free(line);
		free_data(cub);
		exit(1);
	}
}

void	put_ceiling_floor(char *line, char *cf, int *color, t_cub *cub, int fd)
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
			print_duplicate(cf, "color", cub, line, fd);
	}
}

void	assign_data(char *line, t_cub	*cub, int fd)
{
	put_texture(line, "NO ", &cub->texture->no, cub, fd);
	put_texture(line, "SO ", &cub->texture->so, cub, fd);
	put_texture(line, "WE ", &cub->texture->we, cub, fd);
	put_texture(line, "EA ", &cub->texture->ea, cub, fd);
	put_ceiling_floor(line, "F ", cub->floor, cub, fd);
	put_ceiling_floor(line, "C ", cub->ceiling, cub, fd);
	put_map(line, cub, fd);
}

int	travel_file(char *file, t_cub *cub)
{
	int		fd;
	char	*line;
	int		index;

	index = 0;
	if ((ft_strlen(file) <= 4) || ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4) != 0)
		return (print_err("Error\nInvalid file extension\n"));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (print_err("Error\nCannot open file\n"));
	line = get_next_line(fd);
	delete_newline(&line);
	while (line)
	{
		assign_data(line, cub, fd);
		if (cub->map != NULL)
			break;
		if (line != NULL)
		{
			free(line);
			line = get_next_line(fd);
			delete_newline(&line);
		}
		index++;
	}
	close(fd);
	return (0);
}
