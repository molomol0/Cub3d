/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mouvement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:47:35 by ftholoza          #+#    #+#             */
/*   Updated: 2024/04/02 18:20:37 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

int	double_check_forward(t_cub *cub)
{
	init_ray_struct(cub->player);
	cub->player->ray->x = (int)(W_WIDTH / 2);
	cub->player->ray->raydir_x = cub->player->dir_x;
	cub->player->ray->raydir_y = cub->player->dir_y;
	get_delta(cub->player);
	get_side(cub->player);
	fire_ray(cub->player, cub);
	get_perpwall_dist(cub->player);
	if (cub->player->ray->perp_dist < 0.1)
		return (0);
	return (1);
}

int	double_check_backward(t_cub *cub)
{
	init_ray_struct(cub->player);
	cub->player->ray->x = (int)(W_WIDTH / 2);
	cub->player->ray->raydir_x = cub->player->dir_x * -1;
	cub->player->ray->raydir_y = cub->player->dir_y * -1;
	get_delta(cub->player);
	get_side(cub->player);
	fire_ray(cub->player, cub);
	get_perpwall_dist(cub->player);
	if (cub->player->ray->perp_dist < 0.1)
		return (0);
	return (1);
}

int	check_forward(t_cub *cub)
{
	double	pos_x;
	double	pos_y;
	double	map_x;
	double	map_y;

	if (!double_check_forward(cub))
		return (0);
	pos_x = cub->player->pos_x;
	pos_x += cub->player->dir_x * (cub->player->speed * 5);
	pos_y = cub->player->pos_y;
	pos_y += cub->player->dir_y * (cub->player->speed * 5);
	map_x = pos_x / TILE_SIZE;
	map_y = pos_y / TILE_SIZE;
	if (check_if_null(cub->map, (int)map_x, (int)map_y))
		return (0);
	else if (cub->map[(int)map_y][(int)map_x] == '1'
		||cub->map[(int)map_y][(int)map_x] == '3')
		return (0);
	return (1);
}

int	check_backward(t_cub *cub)
{
	double	pos_x;
	double	pos_y;
	double	map_x;
	double	map_y;

	if (!double_check_backward(cub))
		return (0);
	pos_x = cub->player->pos_x;
	pos_x -= cub->player->dir_x * (cub->player->speed * 5);
	pos_y = cub->player->pos_y;
	pos_y -= cub->player->dir_y * (cub->player->speed * 5);
	map_x = pos_x / TILE_SIZE;
	map_y = pos_y / TILE_SIZE;
	if (check_if_null(cub->map, (int)map_x, (int)map_y))
		return (0);
	if (cub->map[(int)map_y][(int)map_x] == '1'
		||cub->map[(int)map_y][(int)map_x] == '3')
		return (0);
	return (1);
}
