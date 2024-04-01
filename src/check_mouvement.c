/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.mouvement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:47:35 by ftholoza          #+#    #+#             */
/*   Updated: 2024/04/01 09:48:13 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

int	check_forward(t_cub *cub)
{
	double	pos_x;
	double	pos_y;
	double	map_x;
	double	map_y;

	pos_x = cub->player->pos_x;
	pos_x += cub->player->dir_x * (PLAYER_SPEED * 5);
	pos_y = cub->player->pos_y;
	pos_y += cub->player->dir_y * (PLAYER_SPEED * 5);
	map_x = pos_x / TILE_SIZE;
	map_y = pos_y / TILE_SIZE;
	if (cub->map[(int)map_y][(int)map_x] == '1'
		||cub->map[(int)map_y][(int)map_x] == '3')
		return (0);
	return (1);
}

int	check_backward(t_cub *cub)
{
	double	pos_x;
	double	pos_y;
	double	map_x;
	double	map_y;

	pos_x = cub->player->pos_x;
	pos_x -= cub->player->dir_x * (PLAYER_SPEED * 5);
	pos_y = cub->player->pos_y;
	pos_y -= cub->player->dir_y * (PLAYER_SPEED * 5);
	map_x = pos_x / TILE_SIZE;
	map_y = pos_y / TILE_SIZE;
	if (cub->map[(int)map_y][(int)map_x] == '1'
		||cub->map[(int)map_y][(int)map_x] == '3')
		return (0);
	return (1);
}
