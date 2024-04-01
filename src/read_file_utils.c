/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:49:17 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/01 09:49:59 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"

void	get_gun_img(t_cub *cub)
{
	cub->texture->pi = ft_strdup("/texture/gun.xpm");
	cub->texture->pif = ft_strdup("/texture/feu.xpm");
	cub->texture->pir1 = ft_strdup("/texture/recul1.xpm");
	cub->texture->pir2 = ft_strdup("/texture/recul2.xpm");
	cub->texture->door = ft_strdup("/texture/door.xpm");
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
