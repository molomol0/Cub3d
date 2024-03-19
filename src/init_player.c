/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:42:34 by ftholoza          #+#    #+#             */
/*   Updated: 2024/03/19 20:16:28 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"

void	init_dir(t_player *player, char **map, int x, int y)
{
	printf("%d, %d\n", x, y);
	if (map[x][y] == 'N')
	{
		player->dir_x = x;
		player->dir_y = y + 1;
	}
	if (map[x][y] == 'S')
	{
		player->dir_x = x;
		player->dir_y = y - 1;
	}
	if (map[x][y] == 'E')
	{
		player->dir_x = x - 1;
		player->dir_y = y;
	}
	if (map[x][y] == 'W')
	{
		player->dir_x = x + 1;
		player->dir_y = y;
	}
	return ;
}

void	set_cam_plane(t_player *player, int fov)
{
	double	lenght_plane;

	lenght_plane = (tan(fov / 2) * 1);
	printf("here: %f\n, %f\n", lenght_plane, tan(fov / 2) * 1);
	player->camera_plane_left_x = player->pos_x - lenght_plane;
	player->camera_plane_left_y = player->pos_y + 1;
	player->camera_plane_right_x = player->pos_x + lenght_plane;
	player->camera_plane_right_y = player->pos_y + 1;
	return ;
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
	set_cam_plane(res, 180);
	return (res);
}
