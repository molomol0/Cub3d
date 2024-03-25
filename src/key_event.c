/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:58:57 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/25 18:39:54 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

void	print_player(t_cub *cub)
{
	printf("---PRINT DES STRUCTS---\n\n");
	printf("ray : \n");
	printf("map_x : %d, map_y : %d \n", cub->player->ray->map_x,  cub->player->ray->map_y);
	printf("perp dist : %f \n\n",  cub->player->ray->perp_dist);

	printf("player :\n");
	printf("pos_x: %f, pos_y: %f\n", cub->player->pos_x, cub->player->pos_y);
	printf("dir_x: %f, dir_y: %f\n", cub->player->dir_x, cub->player->dir_y);
	printf("map_x: %f, map_y: %f\n", cub->player->map_x, cub->player->map_y);

	printf("---FIN PRINT STRUCT---\n");
}

int	move_forward(t_cub *cub)
{
	printf("pos_x: %f, pos_y: %f\n", cub->player->pos_x, cub->player->pos_y);
	cub->player->pos_x += cub->player->dir_x * PLAYER_SPEED;
	cub->player->pos_y += cub->player->dir_y * PLAYER_SPEED;
	printf("pos_x: %f, pos_y: %f\n", cub->player->pos_x, cub->player->pos_y);
	printf("dir_x: %f, dir_y: %f\n", cub->player->dir_x, cub->player->dir_y);
	printf("map_x: %f, map_y: %f\n", cub->player->map_x, cub->player->map_y);
	cub->player->map_x = cub->player->pos_x / TILE_SIZE;
	cub->player->map_y = cub->player->pos_y / TILE_SIZE;
	printf("pointer: %p, map_x: %f, map_y: %f\n", cub->player, cub->player->map_x, cub->player->map_y);
	print_player(cub);
	ray_casting(cub, cub->player);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->buff->img, 0, 0);
	return (0);
}

int	move_backward(t_cub *cub)
{
	cub->player->pos_x -= cub->player->dir_x * PLAYER_SPEED;
	cub->player->pos_y -= cub->player->dir_y * PLAYER_SPEED;
	cub->player->map_x = cub->player->pos_x / TILE_SIZE;
	cub->player->map_y = cub->player->pos_y / TILE_SIZE;
	ray_casting(cub, cub->player);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->buff->img, 0, 0);
	return (0);
}

int	rotate_left(t_cub *cub)
{
	rotate_player(cub->player, -5);
	ray_casting(cub, cub->player);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->buff->img, 0, 0);
	return (0);
}

int	rotate_right(t_cub *cub)
{
	rotate_player(cub->player, 5);
	ray_casting(cub, cub->player);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->buff->img, 0, 0);
	return (0);
}

int		key_event(int keycode, t_cub *cub)
{
	// printf("%d\n", keycode);
	if (keycode == KEY_ESC)
		clean_close(cub);
	if (keycode == KEY_W)
		return move_forward(cub);
	if (keycode == KEY_A)
		return rotate_left(cub);
	if (keycode == KEY_S)
		return move_backward(cub);
	if (keycode == KEY_D)
		return rotate_right(cub);
	return (0);
}
