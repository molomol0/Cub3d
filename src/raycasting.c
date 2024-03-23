/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:03:10 by ftholoza          #+#    #+#             */
/*   Updated: 2024/03/23 04:55:21 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"

void	get_ray_dir(t_player *player)
{
	double	lenght_plane;

	lenght_plane = player->camera_plane_lenght;
	player->ray->raypoint_x = player->map_x
		+ player->dir_x + (player->dir_y * (lenght_plane - player->ray->x));
	player->ray->raypoint_y = player->map_y + player->dir_y
		+ (player->dir_x * -1) * (lenght_plane - player->ray->x);
	player->ray->raydir_x = player->ray->raypoint_x - player->map_x;
	player->ray->raydir_y = player->ray->raypoint_y - player->map_y;
	printf("ray_dir_x: %f, ray_dir_y: %f\n", player->ray->raydir_x, player->ray->raydir_y);
}

void	init_ray_struct(t_player *player)
{
	player->ray->x = 0;
	player->ray->hit = 0;
	player->ray->map_x = player->map_x;
	player->ray->map_y = player->map_y;
	player->ray->scale = (player->camera_plane_lenght * 2) / W_WIDTH;
}

void	get_delta(t_player *player)
{
	t_ray *ray;

	ray = player->ray;
	ray->delta_x = fabs(1 / ray->raydir_x);
	ray->delta_y = fabs(1 / ray->raydir_y);
	ray->delta_x *= 100;
	ray->delta_y *= 100;
}

void	get_side(t_player *player)
{
	if (player->ray->raydir_x < 0)
	{
		player->ray->step_x = -1;
		player->ray->side_x = fabs(player->pos_x
				- player->map_x) * player->ray->delta_x;
	}
	else
	{
		player->ray->step_x = 1;
		player->ray->side_x = fabs(player->map_x + 1.0
				- player->pos_x) * player->ray->delta_x;
	}
	if (player->ray->raydir_y < 0)
	{
		player->ray->step_y = 1;
		player->ray->side_y = fabs(player->pos_y
				- player->map_y) * player->ray->delta_y;
	}
	else
	{
		player->ray->step_y = -1;
		player->ray->side_y = fabs(player->map_y + 1.0
				- player->pos_y) * player->ray->delta_y;
	}
	player->ray->side_x /= 100;
	player->ray->side_y /= 100;
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
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (cub->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	printf("side_x %f, side_y %f, delta_x %f, delta_y %f\n", ray->side_x, ray->side_y, ray->delta_x, ray->delta_y);
	printf("ray %f: hitted wall: y %d, x%d\n", ray->x, ray->map_y, ray->map_x);
}

void	get_perpwall_dist(t_player *player)
{
	t_ray	*ray;

	ray = player->ray;
	if (ray->side == 0)
		ray->perp_dist = fabs(ray->side_x - ray->delta_x);
	else
		ray->perp_dist = fabs(ray->side_y - ray->delta_y);
}

void	ray_casting(t_cub *cub, t_player *player)
{
	init_ray_struct(player);
	while ((player->ray->x - player->ray->scale) <= player->camera_plane_lenght * 2)
	{
		get_ray_dir(player);
		get_delta(player);
		get_side(player);
		fire_ray(player, cub);
		get_perpwall_dist(player);
		render_wall(cub, player->ray);
		player->ray->x += player->ray->scale;
		player->ray->map_x = player->map_x;
		player->ray->map_y = player->map_y;
		player->ray->hit = 0;
	}
	return ;
}
