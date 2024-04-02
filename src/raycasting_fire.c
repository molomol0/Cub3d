/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_fire.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 08:44:54 by ftholoza          #+#    #+#             */
/*   Updated: 2024/04/02 14:08:16 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

void	fire_ray_one(t_player *player, t_cub *cub)
{
	t_ray	*ray;

	ray = player->ray;
	ray->side_x += ray->delta_x;
	ray->map_x -= ray->step_x;
	if (ray->raydir_x > 0)
		ray->side = WEST;
	else
		ray->side = EAST;
	if (cub->map[(int)ray->map_y][(int)ray->map_x] == '3')
		ray->side = DOOR_EW;
}

void	fire_ray_two(t_player *player, t_cub *cub)
{
	t_ray	*ray;

	ray = player->ray;
	ray->side_y += ray->delta_y;
	ray->map_y -= ray->step_y;
	if (ray->raydir_y < 0)
		ray->side = NORTH;
	else
		ray->side = SOUTH;
	if (cub->map[(int)ray->map_y][(int)ray->map_x] == '3')
		ray->side = DOOR_NS;
}

void	fire_ray(t_player *player, t_cub *cub)
{
	t_ray	*ray;

	ray = player->ray;
	while (!ray->hit)
	{
		if (ray->side_x < ray->side_y)
			fire_ray_one(player, cub);
		else
			fire_ray_two(player, cub);
		if (cub->map[(int)ray->map_y][(int)ray->map_x] == '1'
			|| cub->map[(int)ray->map_y][(int)ray->map_x] == '3'
			|| cub->map[(int)ray->map_y][(int)ray->map_x] >= '5')
		{
			ray->hit_type = cub->map[(int)ray->map_y][(int)ray->map_x];
			ray->hit = 1;
			ray->hit_x = (int)ray->map_x;
			ray->hit_y = (int)ray->map_y;
		}
	}
}
