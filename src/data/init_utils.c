/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:55:09 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/02 18:39:52 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

int	check_data(t_cub *cub)
{
	if (cub->texture->no == NULL || cub->texture->so == NULL
		|| cub->texture->we == NULL || cub->texture->ea == NULL
		|| cub->floor[0] == -1 || cub->ceiling[0] == -1 || cub->map == NULL)
	{
		ft_putstr_fd("Error\nMissing data\n", 2);
		return (-1);
	}
	return (0);
}

void	null_init(t_cub *cub)
{
	cub->player = NULL;
	cub->texture->pi = NULL;
	cub->texture->pif = NULL;
	cub->texture->pir1 = NULL;
	cub->texture->pir2 = NULL;
	cub->texture->door = NULL;
	cub->texture->no = NULL;
	cub->texture->so = NULL;
	cub->texture->we = NULL;
	cub->texture->ea = NULL;
	cub->floor[0] = -1;
	cub->ceiling[0] = -1;
	cub->prev_mouse_x = 0;
	cub->end = 0;
	cub->on_of = 0;
	cub->frame_start = 0;
	cub->old_time = 0;
	cub->map = NULL;
	cub->mlx = NULL;
	cub->win = NULL;
	cub->buff = NULL;
	cub->minimap = NULL;
}

int	malloc_texture(t_cub *cub)
{
	cub->texture = malloc(sizeof(t_texture));
	if (!cub->texture)
		return (print_err("Error\nMalloc failed\n"));
	cub->texture->no_img = malloc(sizeof(t_img));
	if (!cub->texture->no_img)
		return (print_err("Error\nMalloc failed\n"));
	cub->texture->so_img = malloc(sizeof(t_img));
	if (!cub->texture->so_img)
		return (print_err("Error\nMalloc failed\n"));
	cub->texture->we_img = malloc(sizeof(t_img));
	if (!cub->texture->we_img)
		return (print_err("Error\nMalloc failed\n"));
	cub->texture->ea_img = malloc(sizeof(t_img));
	if (!cub->texture->ea_img)
		return (print_err("Error\nMalloc failed\n"));
	return (0);
}

int	malloc_pistol(t_cub *cub)
{
	cub->texture->pistol = malloc(sizeof(t_img));
	if (!cub->texture->pistol)
		return (print_err("Error\nMalloc failed\n"));
	cub->texture->pistol_flame = malloc(sizeof(t_img));
	if (!cub->texture->pistol_flame)
		return (print_err("Error\nMalloc failed\n"));
	cub->texture->pistol_r1 = malloc(sizeof(t_img));
	if (!cub->texture->pistol_r1)
		return (print_err("Error\nMalloc failed\n"));
	cub->texture->pistol_r2 = malloc(sizeof(t_img));
	if (!cub->texture->pistol_r2)
		return (print_err("Error\nMalloc failed\n"));
	cub->texture->door_img = malloc(sizeof(t_img));
	if (!cub->texture->door_img)
		return (print_err("Error\nMalloc failed\n"));
	return (0);
}

int	init_buff_minimap(t_cub *cub)
{
	cub->buff = malloc(sizeof(t_img));
	if (!cub->buff)
	{
		ft_putstr_fd("Error\nMalloc failed\n", 2);
		return (-1);
	}
	cub->minimap = malloc(sizeof(t_img));
	if (!cub->minimap)
	{
		ft_putstr_fd("Error\nMalloc failed\n", 2);
		return (-1);
	}
	cub->minimap->img = mlx_new_image(cub->mlx, W_WIDTH / 5, W_HEIGHT / 5);
	cub->minimap->width = W_WIDTH / 5;
	cub->minimap->height = W_HEIGHT / 5;
	cub->minimap->addr = mlx_get_data_addr(cub->minimap->img,
			&cub->minimap->bit_per_pixel, &cub->minimap->line_length,
			&cub->minimap->endian);
	cub->buff->img = mlx_new_image(cub->mlx, W_WIDTH, W_HEIGHT);
	cub->buff->width = W_WIDTH;
	cub->buff->height = W_HEIGHT;
	cub->buff->addr = mlx_get_data_addr(cub->buff->img,
			&cub->buff->bit_per_pixel, &cub->buff->line_length,
			&cub->buff->endian);
	return (0);
}
