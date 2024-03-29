/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:49:17 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/29 16:51:01 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"

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
