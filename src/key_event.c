/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:58:57 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/28 17:39:59 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

int	check_press(int key, t_cub *cub)
{
	if (key == KEY_W)
		cub->player->move[0] = true;
	if (key == KEY_A)
		cub->player->move[1] = true;
	if (key == KEY_S)
		cub->player->move[2] = true;
	if (key == KEY_D)
		cub->player->move[3] = true;
	if (key == KEY_ESC)
		clean_close(cub);
	return (0);
}

int	check_release(int key, t_cub *cub)
{
	if (key == KEY_W)
		cub->player->move[0] = false;
	if (key == KEY_A)
		cub->player->move[1] = false;
	if (key == KEY_S)
		cub->player->move[2] = false;
	if (key == KEY_D)
		cub->player->move[3] = false;
	return (0);
}

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

int	check_forward(t_cub *cub)
{
	double	pos_x;
	double	pos_y;
	double	map_x;
	double	map_y;

	pos_x = cub->player->pos_x;
	pos_x += cub->player->dir_x * PLAYER_SPEED;
	pos_y =	cub->player->pos_y;
	pos_y += cub->player->dir_y * PLAYER_SPEED;
	map_x = pos_x / TILE_SIZE;
	map_y = (pos_y - 5) / TILE_SIZE;
	if (cub->map[(int)map_y][(int)map_x] > '0' || cub->map[(int)(pos_y / TILE_SIZE)][(int)map_x] > '0')
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
	pos_x -= cub->player->dir_x * PLAYER_SPEED;
	pos_y =	cub->player->pos_y;
	pos_y -= cub->player->dir_y * PLAYER_SPEED;
	map_x = pos_x / TILE_SIZE;
	map_y = pos_y / TILE_SIZE;
	if (cub->map[(int)map_y][(int)map_x] > '0')
		return (0);
	return (1);
}

int	move_forward(t_cub *cub)
{
	if (!check_forward(cub))
		return (0);
	cub->player->pos_x += cub->player->dir_x * PLAYER_SPEED;
	cub->player->pos_y += cub->player->dir_y * PLAYER_SPEED;
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
	cub->player->pos_x -= cub->player->dir_x * PLAYER_SPEED;
	cub->player->pos_y -= cub->player->dir_y * PLAYER_SPEED;
	cub->player->map_x = cub->player->pos_x / TILE_SIZE;
	cub->player->map_y = cub->player->pos_y / TILE_SIZE;
	ray_casting(cub, cub->player);
	draw_minimap(cub);
	return (0);
}

int	rotate_left(t_cub *cub, int rotate)
{
	rotate_player(cub->player, -rotate);
	ray_casting(cub, cub->player);
	draw_minimap(cub);
	return (0);
}

int	rotate_right(t_cub *cub, int rotate)
{
	rotate_player(cub->player, rotate);
	ray_casting(cub, cub->player);
	draw_minimap(cub);
	return (0);
}

void	do_move(t_cub *cub)
{
	if (cub->player->move[0])
		move_forward(cub);
	if (cub->player->move[1])
		rotate_left(cub, 5);
	if (cub->player->move[2])
		move_backward(cub);
	if (cub->player->move[3])
		rotate_right(cub, 5);
}

int	key_anim(int keycode, t_cub *cub)
{
	if (keycode == 65513)
	{
		cub->on_of = 1;
	}
	return (0);
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
	if (x > (W_WIDTH - 100))
		mlx_mouse_move(cub->mlx, cub->win, W_WIDTH / 2, y);
	if (x < 100)
		mlx_mouse_move(cub->mlx, cub->win, W_WIDTH / 2 + 100, y);
	//printf("%d, %d\n", x, cub->prev_mouse_x);
	if (x > cub->prev_mouse_x)
		rotate_right(cub, 2);
	else if (x < cub->prev_mouse_x)
		rotate_left(cub, 2);
	else
		return (0);
	cub->prev_mouse_x = x;
	return (0);
}
