/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:03:10 by ftholoza          #+#    #+#             */
/*   Updated: 2024/03/22 16:31:35 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"

void	get_ray_dir(t_player *player)
{
	double	lenght_plane;

	lenght_plane = (player->camera_plane_lenght / 2);
	player->ray->raypoint_x = player->pos_x
		+ player->dir_x + (player->dir_y * (lenght_plane - player->ray->x));
	player->ray->raypoint_y = player->pos_y + player->dir_y
		+ (player->dir_x * -1) * (lenght_plane - player->ray->x);
	player->ray->raydir_x = player->ray->raypoint_x - player->pos_x;
	player->ray->raydir_y = player->ray->raypoint_y - player->pos_y;
	//player->ray->delta_y *= -1;
}

void	init_ray_struct(t_player *player)
{
	player->ray->x = 0;
	player->ray->hit = 0;
	//player->ray->distance = 0;
	player->ray->map_x = player->pos_x;
	player->ray->map_y = player->pos_y;
	player->ray->scale = player->camera_plane_lenght / W_WIDTH;
}

void	get_delta(t_player *player)
{
	player->ray->delta_x = sqrt(1 + (pow(player->ray->raydir_y, 2))
			/ (pow(player->ray->raydir_x, 2)));
	player->ray->delta_y = sqrt(1 + (pow(player->ray->raydir_x, 2))
			/ (pow(player->ray->raydir_y, 2)));
	player->ray->delta_x *= TILE_SIZE;
	player->ray->delta_y *= TILE_SIZE;
	//player->ray->delta_y *= -1;
	//printf("deltax: %f, deltay: %f\n",
	//	player->ray->delta_x, player->ray->delta_y);
}

void	get_side(t_player *player)
{
	player->ray->delta_x /= TILE_SIZE;
	player->ray->delta_y /= TILE_SIZE;
	player->pos_x *= TILE_SIZE;
	player->pos_y *= TILE_SIZE;
	if (player->ray->raydir_x < 0)
	{
		player->ray->step_x = -1;
		player->ray->side_x = (player->pix_px
				- player->pos_x) * player->ray->delta_x;
	}
	else
	{
		player->ray->step_x = 1;
		player->ray->side_x = (player->pos_x + 1.0
				- player->pix_px) * player->ray->delta_x;
	}
	if (player->ray->raydir_y < 0)
	{
		player->ray->step_y = 1;
		player->ray->side_y = (player->pix_py
				- player->pos_y) * player->ray->delta_y;
	}
	else
	{
		player->ray->step_y = -1;
		player->ray->side_y = (player->pos_y + 1.0
				- player->pix_py) * player->ray->delta_y;
	}
	player->pos_x /= TILE_SIZE;
	player->pos_y /= TILE_SIZE;
	player->ray->delta_x *= TILE_SIZE;
	player->ray->delta_y *= TILE_SIZE;
	//player->ray->delta_y *= -1;
	//printf("side_x: %f, side_y: %f\n", player->ray->side_x, player->ray->side_y);
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
		//printf("side x: %f, side y: %f\n", ray->side_x, ray->side_y);
		//printf("mapx %d, mapy %d\n", ray->map_x, ray->map_y);
		if (cub->map[ray->map_y][ray->map_x] > '0')
			ray->hit = 1;
	}
	ray->eu_dist = 1;
	//printf("%c\n", cub->map[ray->map_y][ray->map_x]);
}

void	get_perpwall_dist(t_player *player)
{
	double	y_dist;
	t_ray	*ray;

	
	ray = player->ray;
	printf("sidey %f, deltay %f\n", ray->side_y, ray->delta_y);
	printf("%f\n", ray->raydir_y);
	y_dist = (ray->side_y - ray->delta_y);
	ray->perp_dist = fabs(y_dist / ray->raydir_y) * 100;
	printf("ydist: %f\n", y_dist);
	printf("perp_dist: %f\n", ray->perp_dist);
}

void	ray_casting(t_cub *cub, t_player *player)
{
	printf("%p\n", player);
	init_ray_struct(player);
	(void)cub;
	double	tempx = 0;
	double	tempy = 0;
	while ((player->ray->x - player->ray->scale) <= player->camera_plane_lenght)
	{
		get_ray_dir(player);
		//printf("ray_dir_x: %f\nray_dir_y: %f\n",
		//	player->ray->raydir_x, player->ray->raydir_y);
		get_delta(player);
		get_side(player);
		fire_ray(player, cub);
		get_perpwall_dist(player);
		if (player->ray->x == 0 || (player->ray->map_x != tempx && player->ray->map_y != tempy))
			printf("ray hits: mapx: %d, mapy: %d\n", player->ray->map_x, player->ray->map_y);
		player->ray->x += player->ray->scale;
		player->ray->map_x = player->pos_x;
		player->ray->map_y = player->pos_y;
		player->ray->hit = 0;
		tempx = player->ray->map_x;
		tempy = player->ray->map_y;
		printf("%f\n", player->ray->x / player->ray->scale);
	}
	return ;
}
