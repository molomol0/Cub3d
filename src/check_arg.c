/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:27:42 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/01 09:41:48 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "libft.h"

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
	if (color[0] < 0 || color[1] < 0 || color[2] < 0 || color[0] > 255
		|| color[1] > 255 || color[2] > 255)
	{
		ft_putstr_fd("Error\nInvalid color\n", 2);
		free(line);
		free_data(cub);
		exit(1);
	}
}

void	print_duplicate(char *duplicated, char *type, t_cub *cub, char *line)
{
	ft_putstr_fd("Error\nDuplicate ", 2);
	ft_putstr_fd(duplicated, 2);
	ft_putstr_fd(type, 2);
	ft_putstr_fd("\n", 2);
	while (line)
	{
		free(line);
		line = get_next_line(cub->tmp);
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

int	skip_space(char *line, char *id)
{
	int	index;

	index = ft_strlen(id);
	while ((line[index] >= '\t' && line[index] <= '\r') || line[index] == ' ')
		index++;
	return (index);
}
