/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:42:34 by ftholoza          #+#    #+#             */
/*   Updated: 2024/03/22 20:33:01 by francesco        ###   ########.fr       */
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
	player->dir_x *= TILE_SIZE;
	player->dir_y *= TILE_SIZE;
	return ;
}

void	set_cam_plane(t_player *player)
{
	double	lenght_plane;

	lenght_plane = (tan(FOV / 2));
	player->camera_plane_lenght = lenght_plane * 2;
	player->camera_plane_right_x = player->pix_px
		+ player->dir_x + (player->dir_y * lenght_plane);
	player->camera_plane_right_y = player->pix_py
		+ player->dir_y + (player->dir_x * -1) * lenght_plane;
	player->camera_plane_left_x = player->pix_px
		+ player->dir_x + (player->dir_y * -1) * lenght_plane;
	player->camera_plane_left_y = player->pix_py
		+ player->dir_y + (player->dir_x * lenght_plane);
	return ;
}

void	rotate_player(t_player *player, int degrees)
{
	double	radiant;
	double	temp;

	//printf("here:%f\n", (player->dir_x));
	radiant = degrees * (M_PI / 180);
	temp = player->dir_x;
	player->dir_x = (player->dir_x * cos(radiant))
		- (player->dir_y * sin(radiant));
	player->dir_y = (player->dir_y * cos(radiant)) + (temp * sin(radiant));
	set_cam_plane(player);
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
	res->ray = malloc(sizeof(t_ray));
	if (!res->ray)
		printf("error: malloc\n");
	res->pos_x = x;
	res->pos_y = y;
	init_dir(res, map, x, y);
	res->pix_px = (res->pos_x * TILE_SIZE) + (TILE_SIZE / 2);
	res->pix_py = (res->pos_y * TILE_SIZE) + (TILE_SIZE / 2);
	set_cam_plane(res);
	return (res);
}
