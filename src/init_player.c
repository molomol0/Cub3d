/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:42:34 by ftholoza          #+#    #+#             */
/*   Updated: 2024/04/01 01:57:33 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "math.h"

void	init_dir(t_player *player, char **map, int x, int y)
{
	if (map[y][x] == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	if (map[y][x] == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	if (map[y][x] == 'E')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
	if (map[y][x] == 'W')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	map[y][x] = '0';
	return ;
}

void	set_cam_plane(t_player *player)
{
	double	lenght_plane;

	lenght_plane = (tan(FOV / 2));
	player->camera_plane_lenght = lenght_plane;
	player->camera_plane_right_x = player->map_x + player->dir_x
		+ (player->dir_y * lenght_plane);
	player->camera_plane_right_y = player->map_y + player->dir_y
		+ (player->dir_x * -1) * lenght_plane;
	player->camera_plane_left_x = player->map_x + player->dir_x + (player->dir_y
			* -1) * lenght_plane;
	player->camera_plane_left_y = player->map_y + player->dir_y + (player->dir_x
			* lenght_plane);
	return ;
}

void	rotate_player(t_player *player, int degrees)
{
	double	radiant;
	double	temp;

	radiant = degrees * (M_PI / 180);
	temp = player->dir_x;
	player->dir_x = (player->dir_x * cos(radiant)) - (player->dir_y
			* sin(radiant));
	player->dir_y = (player->dir_y * cos(radiant)) + (temp * sin(radiant));
	set_cam_plane(player);
}

t_player	*player_struct_init(char **map)
{
	t_player	*res;
	int			x;
	int			y;
	int			i;

	res = malloc(sizeof(t_player));
	if (!res)
		return (NULL);
	res->ray = malloc(sizeof(t_ray));
	if (!res->ray)
		return (NULL);
	find_spawn(map, &x, &y);
	res->map_x = x + 0.5;
	res->map_y = y + 0.5;
	init_dir(res, map, x, y);
	res->pos_x = (res->map_x * TILE_SIZE);
	res->pos_y = (res->map_y * TILE_SIZE);
	set_cam_plane(res);
	i = 0;
	while (i < 4)
	{
		res->move[i] = false;
		i++;
	}
	return (res);
}
