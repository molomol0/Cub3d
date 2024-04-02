/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:45:00 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/02 18:24:16 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

int	move_forward(t_cub *cub)
{
	if (!check_forward(cub))
		return (0);
	cub->player->pos_x += cub->player->dir_x * cub->player->speed;
	cub->player->pos_y += cub->player->dir_y * cub->player->speed;
	cub->player->map_x = cub->player->pos_x / TILE_SIZE;
	cub->player->map_y = cub->player->pos_y / TILE_SIZE;
	ray_casting(cub, cub->player);
	draw_minimap(cub);
	return (0);
}

int	move_backward(t_cub *cub)
{
	if (!check_backward(cub))
		return (0);
	cub->player->pos_x -= cub->player->dir_x * cub->player->speed;
	cub->player->pos_y -= cub->player->dir_y * cub->player->speed;
	cub->player->map_x = cub->player->pos_x / TILE_SIZE;
	cub->player->map_y = cub->player->pos_y / TILE_SIZE;
	ray_casting(cub, cub->player);
	draw_minimap(cub);
	return (0);
}

int	rotate_left(t_cub *cub, int rotate)
{
	rotate_player(cub->player, -rotate);
	return (0);
}

int	rotate_right(t_cub *cub, int rotate)
{
	rotate_player(cub->player, rotate);
	return (0);
}

void	do_move(t_cub *cub)
{
	if (cub->player->move[0])
		move_forward(cub);
	if (cub->player->move[1])
		rotate_left(cub, 2);
	if (cub->player->move[2])
		move_backward(cub);
	if (cub->player->move[3])
		rotate_right(cub, 2);
}
