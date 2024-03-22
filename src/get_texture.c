/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:32:19 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/22 16:38:40 by jdenis           ###   ########.fr       */
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
	cub->texture->no_img->img = mlx_xpm_file_to_image(cub->mlx, cub->texture->no + 1, &cub->texture->no_img->width, &cub->texture->no_img->height);
	if (!cub->texture->no_img->img)
	{
		ft_putstr_fd("Error\nTexture not found\n", 2);
		free_data(cub);
		exit(1);
	}
	cub->texture->no_img->addr = mlx_get_data_addr(cub->texture->no_img, &cub->texture->no_img->bit_per_pixel, &cub->texture->no_img->line_length, &cub->texture->no_img->endian);
	cub->texture->so_img->img = mlx_xpm_file_to_image(cub->mlx, cub->texture->so + 1, &cub->texture->so_img->width, &cub->texture->so_img->height);
	if (!cub->texture->so_img->img)
	{
		ft_putstr_fd("Error\nTexture not found\n", 2);
		free_data(cub);
		exit(1);
	}
	cub->texture->so_img->addr = mlx_get_data_addr(cub->texture->so_img, &cub->texture->so_img->bit_per_pixel, &cub->texture->so_img->line_length, &cub->texture->so_img->endian);
	cub->texture->we_img->img = mlx_xpm_file_to_image(cub->mlx, cub->texture->we + 1, &cub->texture->we_img->width, &cub->texture->we_img->height);
	if (!cub->texture->we_img->img)
	{
		ft_putstr_fd("Error\nTexture not found\n", 2);
		free_data(cub);
		exit(1);
	}
	cub->texture->we_img->addr = mlx_get_data_addr(cub->texture->we_img, &cub->texture->we_img->bit_per_pixel, &cub->texture->we_img->line_length, &cub->texture->we_img->endian);
	cub->texture->ea_img->img = mlx_xpm_file_to_image(cub->mlx, cub->texture->ea + 1, &cub->texture->ea_img->width, &cub->texture->ea_img->height);
	if (!cub->texture->ea_img->img)
	{
		ft_putstr_fd("Error\nTexture not found\n", 2);
		free_data(cub);
		exit(1);
	}
	cub->texture->ea_img->addr = mlx_get_data_addr(cub->texture->ea_img, &cub->texture->ea_img->bit_per_pixel, &cub->texture->ea_img->line_length, &cub->texture->ea_img->endian);
}
