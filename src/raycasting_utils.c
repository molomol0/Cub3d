/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:40:12 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/01 08:44:13 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

void	get_ray_dir(t_player *player)
{
	double	lenght_plane;

	lenght_plane = player->camera_plane_lenght;
	player->ray->raypoint_x = player->map_x + player->dir_x + (player->dir_y
			* (lenght_plane - player->ray->x / player->ray->scale));
	player->ray->raypoint_y = player->map_y + player->dir_y + (player->dir_x
			* -1) * (lenght_plane - player->ray->x / player->ray->scale);
	player->ray->raydir_x = player->ray->raypoint_x - player->map_x;
	player->ray->raydir_y = player->ray->raypoint_y - player->map_y;
}

void	get_delta(t_player *player)
{
	t_ray	*ray;

	ray = player->ray;
	ray->delta_x = fabs(1 / ray->raydir_x);
	ray->delta_y = fabs(1 / ray->raydir_y);
}

void	get_side(t_player *player)
{
	if (player->ray->raydir_x < 0)
	{
		player->ray->step_x = 1;
		player->ray->side_x = fabs(player->map_x - player->ray->map_x)
			* player->ray->delta_x;
	}
	else
	{
		player->ray->step_x = -1;
		player->ray->side_x = fabs(player->ray->map_x + 1.0 - player->map_x)
			* player->ray->delta_x;
	}
	if (player->ray->raydir_y < 0)
	{
		player->ray->step_y = 1;
		player->ray->side_y = fabs(player->map_y - player->ray->map_y)
			* player->ray->delta_y;
	}
	else
	{
		player->ray->step_y = -1;
		player->ray->side_y = fabs(player->ray->map_y + 1.0 - player->map_y)
			* player->ray->delta_y;
	}
}
