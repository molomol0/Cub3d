/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:42:34 by ftholoza          #+#    #+#             */
/*   Updated: 2024/03/21 00:48:07 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "math.h"

void	init_dir(t_player *player, char **map, int x, int y)
{
	printf("%d, %d\n", x, y);
	if (map[x][y] == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	if (map[x][y] == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	if (map[x][y] == 'E')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
	if (map[x][y] == 'W')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	return ;
}

void	set_cam_plane(t_player *player)
{
	double	lenght_plane;

	lenght_plane = (tan(FOV / 2) * 1);
	player->camera_plane_right_x = player->pos_x
		+ player->dir_x + (player->dir_y * lenght_plane);
	player->camera_plane_right_y = player->pos_y
		+ player->dir_y + (player->dir_x * -1) * lenght_plane;
	player->camera_plane_left_x = player->pos_x
		+ player->dir_x + (player->dir_y * -1) * lenght_plane;
	player->camera_plane_left_y = player->pos_y
		+ player->dir_y + (player->dir_x * lenght_plane);
	printf("cam_right: x:%f, y: %f\n", player->camera_plane_right_x, player->camera_plane_right_y);
	printf("cam_left: x:%f, y:%f\n", player->camera_plane_left_x, player->camera_plane_left_y);
	return ;
}

void	rotate_player(t_player *player, int degrees)
{
	double	radiant;
	double	temp;
	
	radiant = degrees * (M_PI / 180);
	temp = player->dir_x;
	player->dir_x = (player->dir_x * cos(radiant)) - (player->dir_y * sin(radiant));
	player->dir_y = (player->dir_y * cos(radiant)) + (temp * sin(radiant));
	set_cam_plane(player);
	//printf("dir_x: %f, dir_y: %f\n", player->dir_x, player->dir_y);
	
}

t_player	*player_struct_init(char **map)
{
	t_player	*res;
	int			x;
	int			y;

	res = malloc(sizeof(*res));
	if (!res)
		return (res);
	find_spawn(map, &x, &y);
	res->pos_x = x;
	res->pos_y = y;
	init_dir(res, map, x, y);
	set_cam_plane(res);
	return (res);
}
