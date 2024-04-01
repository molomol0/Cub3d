/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:32:19 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/01 09:55:09 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

int	texture_valid(char *texture)
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
	if (ft_strncmp(texture + ft_strlen(texture) - 4, ".xpm", 4) != 0)
	{
		ft_putstr_fd("Error\nTexture must be .xpm\n", 2);
		return (-1);
	}
	fd = open(texture, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nTexture not found\n", 2);
		return (-1);
	}
	close(fd);
	return (0);
}

void	init_texture(t_img *img, t_cub *cub, char *path)
{
	img->img = mlx_xpm_file_to_image(cub->mlx, path + 1, &img->width,
			&img->height);
	if (!img->img)
	{
		ft_putstr_fd("Error\nTexture not found\n", 2);
		free_data(cub);
		exit(1);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bit_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
	{
		ft_putstr_fd("Error\nTexture not found\n", 2);
		free_data(cub);
		exit(1);
	}
}

void	get_texture(t_cub *cub)
{
	init_texture(cub->texture->no_img, cub, cub->texture->no);
	init_texture(cub->texture->so_img, cub, cub->texture->so);
	init_texture(cub->texture->we_img, cub, cub->texture->we);
	init_texture(cub->texture->ea_img, cub, cub->texture->ea);
	init_texture(cub->texture->door_img, cub, cub->texture->door);
	init_texture(cub->texture->pistol, cub, cub->texture->pi);
	init_texture(cub->texture->pistol_flame, cub, cub->texture->pif);
	init_texture(cub->texture->pistol_r1, cub, cub->texture->pir1);
	init_texture(cub->texture->pistol_r2, cub, cub->texture->pir2);
}
