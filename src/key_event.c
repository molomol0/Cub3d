/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:58:57 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/02 14:17:01 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

int	open_close(int i, int j, t_cub *cub)
{
	if (cub->map[j][i] == '4')
	{
		cub->map[j][i] = '3';
		return (1);
	}
	if (cub->map[j][i] == '3')
	{
		cub->map[j][i] = '4';
		return (1);
	}
	return (0);
}

void	fire_ray_doors(t_player *player, t_cub *cub)
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
			|| cub->map[(int)ray->map_y][(int)ray->map_x] >= '4')
		{
			ray->hit_type = cub->map[(int)ray->map_y][(int)ray->map_x];
			ray->hit = 1;
			ray->hit_x = (int)ray->map_x;
			ray->hit_y = (int)ray->map_y;
		}
	}
}

void	check_doors(t_cub *cub)
{
	init_ray_struct(cub->player);
	cub->player->ray->x = (int)(W_WIDTH / 2);
	cub->player->ray->raydir_x = cub->player->dir_x;
	cub->player->ray->raydir_y = cub->player->dir_y;
	get_delta(cub->player);
	get_side(cub->player);
	fire_ray_doors(cub->player, cub);
	get_perpwall_dist(cub->player);
	if ((cub->player->ray->hit_type == '3'
			|| cub->player->ray->hit_type == '4')
		&& cub->player->ray->perp_dist < 0.5)
		open_close(cub->player->ray->hit_x, cub->player->ray->hit_y, cub);
	return ;
}

int	mouse_event(int code, int x, int y, t_cub *cub)
{
	(void)x;
	(void)y;
	if (code == 1)
	{
		cub->on_of = 1;
	}
	return (0);
}

int	mouse_track(int x, int y, t_cub *cub)
{
	if (cub->prev_mouse_x == 0)
		cub->prev_mouse_x = x;
	if (x > (W_WIDTH / 2 + 100))
		mlx_mouse_move(cub->mlx, cub->win, W_WIDTH / 2, y);
	if (x < W_WIDTH / 2 - 100)
		mlx_mouse_move(cub->mlx, cub->win, W_WIDTH / 2, y);
	if (x > cub->prev_mouse_x)
		rotate_right(cub, 3);
	else if (x < cub->prev_mouse_x)
		rotate_left(cub, 3);
	else
	{
		cub->prev_mouse_x = x;
		return (0);
	}
	cub->prev_mouse_x = x;
	return (0);
}
