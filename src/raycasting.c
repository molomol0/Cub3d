/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:03:10 by ftholoza          #+#    #+#             */
/*   Updated: 2024/03/25 18:43:22 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"

void	get_ray_dir(t_player *player)
{
	double	lenght_plane;

	lenght_plane = player->camera_plane_lenght;
	player->ray->raypoint_x = player->map_x
		+ player->dir_x + (player->dir_y * (lenght_plane - player->ray->x / player->ray->scale));
	player->ray->raypoint_y = player->map_y + player->dir_y
		+ (player->dir_x * -1) * (lenght_plane - player->ray->x / player->ray->scale);
	player->ray->raydir_x = player->ray->raypoint_x - player->map_x;
	player->ray->raydir_y = player->ray->raypoint_y - player->map_y;
	//printf("ray_dir_x: %f, ray_dir_y: %f\n", player->ray->raydir_x, player->ray->raydir_y);
}

void	init_ray_struct(t_player *player)
{
	printf("dans le init: %p\n", player);
	player->ray->x = 0;
	player->ray->hit = 0;
	//printf("valeur des map dans l'init : map_x : %d, map_y : %d\n", player->ray->map_x,  player->ray->map_x);
	//printf("valeur des map des plyaer dans l'init : map_x : %f, map_y : %f\n", player->map_x,  player->map_x);
	player->ray->map_x = (int)player->map_x;
	player->ray->map_y = (int)player->map_y;
	printf("here2: pointer: %p, map_x: %f, map_y: %f\n", player, player->map_x, player->map_y);
	printf("here2: pointer: %p, map_x: %d, map_y: %d\n", player, player->ray->map_x, player->ray->map_y);
	
	player->ray->scale = W_WIDTH / (player->camera_plane_lenght * 2);
}

void	get_delta(t_player *player)
{
	t_ray *ray;

	ray = player->ray;
	ray->delta_x = fabs(1 / ray->raydir_x);
	ray->delta_y = fabs(1 / ray->raydir_y);
}

void	get_side(t_player *player)
{
	if (player->ray->raydir_x < 0)
	{
		player->ray->step_x = 1;
		player->ray->side_x = fabs(player->map_x
				- player->ray->map_x) * player->ray->delta_x;
	}
	else
	{
		player->ray->step_x =-1;
		player->ray->side_x = fabs(player->ray->map_x + 1.0
				- player->map_x) * player->ray->delta_x;
	}
	if (player->ray->raydir_y < 0)
	{
		player->ray->step_y = 1;
		player->ray->side_y = fabs(player->map_y
				- player->ray->map_y) * player->ray->delta_y;
	}
	else
	{
		player->ray->step_y = -1;
		player->ray->side_y = fabs(player->ray->map_y + 1.0
				- player->map_y) * player->ray->delta_y;
	}
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
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y -= ray->step_y;
			ray->side = 1;
		}
		if (cub->map[(int)ray->map_y][(int)ray->map_x] == '1')
			ray->hit = 1;
	}
	// printf("side_x %f, side_y %f, delta_x %f, delta_y %f\n", ray->side_x, ray->side_y, ray->delta_x, ray->delta_y);
	//printf("ray %f: hitted wall: y %d, x%d\n", ray->x, ray->map_y, ray->map_x);
}

void	get_perpwall_dist(t_player *player)
{
	t_ray	*ray;

	ray = player->ray;
	if (ray->side == 0)
		ray->perp_dist = fabs(ray->side_x - ray->delta_x);
	else
		ray->perp_dist = fabs(ray->side_y - ray->delta_y);
	ray->perp_dist *= TILE_SIZE;
}

void	ray_casting(t_cub *cub, t_player *player)
{

		printf("here: pointer: %p, map_x: %f, map_y: %f\n", cub->player, cub->player->map_x, cub->player->map_y);
	init_ray_struct(cub->player);
	while ((player->ray->x) <= W_WIDTH - 1)
	{
		get_ray_dir(player);
		get_delta(player);
		get_side(player);
		fire_ray(player, cub);
		get_perpwall_dist(player);
		// print_player(cub);
		render_wall(cub, player->ray);
		player->ray->x += 1;
		player->ray->map_x = player->map_x;
		player->ray->map_y = player->map_y;
		player->ray->hit = 0;
		//printf("%f, %f\n", player->ray->x, player->ray->perp_dist);
	}
	return ;
}
