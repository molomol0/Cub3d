/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:03:10 by ftholoza          #+#    #+#             */
/*   Updated: 2024/03/21 19:56:47 by ftholoza         ###   ########.fr       */
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
}

void	init_ray_struct(t_player *player)
{
	player->ray->x = 0;
	player->ray->scale = player->camera_plane_lenght / W_WIDTH;
}

void	get_delta(t_player *player)
{
	player->ray->delta_x = sqrt(1 + (pow(player->ray->raydir_y, 2))
			/ (pow(player->ray->raydir_x, 2)));
	player->ray->delta_y = sqrt(1 + (pow(player->ray->raydir_x, 2))
			/ (pow(player->ray->raydir_y, 2)));
	printf("deltax: %f, deltay: %f\n",
		player->ray->delta_x, player->ray->delta_y);
}

void	get_side(t_player *player)
{
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
		player->ray->step_y = -1;
		player->ray->side_y = (player->pix_py
				- player->pos_y) * player->ray->delta_y;
	}
	else
	{
		player->ray->step_y = 1;
		player->ray->side_y = (player->pos_y + 1.0
				- player->pix_py) * player->ray->delta_y;
	}
	printf("side_x: %f, side_y: %f\n", player->ray->side_x, player->ray->side_y);
}

void	ray_casting(t_player *player)
{
	printf("%p\n", player);
	init_ray_struct(player);
	/*while ((player->ray->x - player->ray->scale) <= player->camera_plane_lenght)
	{
		get_ray_dir(player);
		//printf("ray_point_x: %f\nray_point_y: %f\n",
			player->ray->raypoint_x, player->ray->raypoint_y);
		//printf("ray_dir_x: %f\nray_dir_y: %f\n",
			player->ray->raydir_x, player->ray->raydir_y);
		//printf("caml: %f\n", player->camera_plane_lenght);
		player->ray->x += player->ray->scale;
		//printf("x: %f\n", player->ray->x);
	}*/
	get_ray_dir(player);
	printf("ray_dir_x: %f\nray_dir_y: %f\n",
		player->ray->raydir_x, player->ray->raydir_y);
	get_delta(player);
	get_side(player);
	return ;
}
