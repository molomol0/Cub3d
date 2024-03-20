/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:32:19 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/20 20:18:50 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

int		texture_valid(char *texture)
{
	int	fd;

	if (!texture)
	{
		ft_putstr_fd("Error\nTexture not found\n", 2);
		return (-1);
	}
	if (ft_strncmp(texture, "./", 2) != 0)
	{
		ft_putstr_fd("Error\nTexture not in right format\n", 2);
		return (-1);
	}
	fd = open(texture, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nTexture not found\n", 2);
		return (-1);
	}
	close(fd);
	if (ft_strncmp(texture + ft_strlen(texture) - 4, ".xpm", 4) != 0)
	{
		ft_putstr_fd("Error\nTexture must be .xpm\n", 2);
		return (-1);
	}
	return (0);
}

void	get_texture(t_cub *cub)
{
	int height = W_HEIGHT;
	int width = W_WIDTH;

	cub->texture->no_img = mlx_xpm_file_to_image(cub->mlx, cub->texture->no + 1, &width, &height);
	cub->texture->so_img = mlx_xpm_file_to_image(cub->mlx, cub->texture->so + 1, &width, &height);
	cub->texture->we_img = mlx_xpm_file_to_image(cub->mlx, cub->texture->we + 1, &width, &height);
	cub->texture->ea_img = mlx_xpm_file_to_image(cub->mlx, cub->texture->ea + 1, &width, &height);
}
