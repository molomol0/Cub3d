/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:03:10 by ftholoza          #+#    #+#             */
/*   Updated: 2024/04/01 07:58:29 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

void	init_ray_struct(t_player *player)
{
	player->ray->x = 0;
	player->ray->hit = 0;
	player->ray->map_x = (int)player->map_x;
	player->ray->map_y = (int)player->map_y;
	player->ray->scale = W_WIDTH / (player->camera_plane_lenght * 2);
}

void	fire_ray(t_player *player, t_cub *cub)
{
	t_ray	*ray;

	ray = player->ray;
	while (!ray->hit)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x -= ray->step_x;
			if (ray->raydir_x > 0)
				ray->side = WEST;
			else
				ray->side = EAST;
			if (cub->map[(int)ray->map_y][(int)ray->map_x] == '3')
				ray->side = DOOR_EW;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y -= ray->step_y;
			if (ray->raydir_y < 0)
				ray->side = NORTH;
			else
				ray->side = SOUTH;
			if (cub->map[(int)ray->map_y][(int)ray->map_x] == '3')
				ray->side = DOOR_NS;
		}
		if (cub->map[(int)ray->map_y][(int)ray->map_x] == '1'
			|| cub->map[(int)ray->map_y][(int)ray->map_x] == '3')
			ray->hit = 1;
	}
}

void	get_perpwall_dist(t_player *player)
{
	t_ray	*ray;

	ray = player->ray;
	if (ray->side == WEST || ray->side == EAST || ray->side == DOOR_EW)
		ray->perp_dist = fabs(ray->side_x - ray->delta_x);
	else
		ray->perp_dist = fabs(ray->side_y - ray->delta_y);
	if (ray->perp_dist == 0)
		ray->perp_dist = 0.1;
}

void	ray_casting(t_cub *cub, t_player *player)
{
	init_ray_struct(cub->player);
	while ((player->ray->x) <= W_WIDTH - 1)
	{
		get_ray_dir(player);
		get_delta(player);
		get_side(player);
		fire_ray(player, cub);
		get_perpwall_dist(player);
		render_wall(cub, player->ray);
		player->ray->x += 1;
		player->ray->map_x = player->map_x;
		player->ray->map_y = player->map_y;
		player->ray->hit = 0;
	}
	return ;
}
