/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:58:57 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/28 05:18:18 by francesco        ###   ########.fr       */
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
	map_y = pos_y / TILE_SIZE;
	if (cub->map[(int)map_y][(int)map_x] > '0')
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
	mlx_put_image_to_window(cub->mlx, cub->win, cub->buff->img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->minimap->img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->texture->pistol->img, (W_WIDTH / 2) - (cub->texture->pistol->width / 2), W_HEIGHT - cub->texture->pistol->height - 65);
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
	mlx_put_image_to_window(cub->mlx, cub->win, cub->buff->img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->minimap->img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->texture->pistol->img, (W_WIDTH / 2) - (cub->texture->pistol->width / 2), W_HEIGHT - cub->texture->pistol->height - 65);
	return (0);
}

int	rotate_left(t_cub *cub, int rotate)
{
	rotate_player(cub->player, -rotate);
	ray_casting(cub, cub->player);
	draw_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->buff->img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->minimap->img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->texture->pistol->img, (W_WIDTH / 2) - (cub->texture->pistol->width / 2), W_HEIGHT - cub->texture->pistol->height - 65);
	return (0);
}

int	rotate_right(t_cub *cub, int rotate)
{
	rotate_player(cub->player, rotate);
	ray_casting(cub, cub->player);
	draw_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->buff->img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->minimap->img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->texture->pistol->img, (W_WIDTH / 2) - (cub->texture->pistol->width / 2), W_HEIGHT - cub->texture->pistol->height - 65);
	return (0);
}

int	fire_anim(t_cub *cub)
{
	mlx_put_image_to_window(cub->mlx, cub->win, cub->buff->img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->minimap->img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->texture->pistol_flame->img, (W_WIDTH / 2) - (cub->texture->pistol_flame->width / 2), W_HEIGHT - cub->texture->pistol_flame->height - 65);
	//mlx_put_image_to_window(cub->mlx, cub->win, cub->texture->pistol_r1->img, (W_WIDTH / 2) - (cub->texture->pistol_r1->width / 2), W_HEIGHT - cub->texture->pistol_r1->height - 65);
	//mlx_put_image_to_window(cub->mlx, cub->win, cub->texture->pistol_r2->img, (W_WIDTH / 2) - (cub->texture->pistol_r2->width / 2), W_HEIGHT - cub->texture->pistol_r2->height - 65);
	//sleep(1);
	//mlx_put_image_to_window(cub->mlx, cub->win, cub->texture->pistol->img, (W_WIDTH / 2) - (cub->texture->pistol->width / 2), W_HEIGHT - cub->texture->pistol->height - 65);
	//printf("ok\n");
	return (0);
}

int		key_event(int keycode, t_cub *cub)
{
	//printf("%d\n", keycode);
	if (keycode == KEY_ESC)
		clean_close(cub);
	if (keycode == KEY_W)
		return move_forward(cub);
	if (keycode == KEY_A)
		return rotate_left(cub, 5);
	if (keycode == KEY_S)
		return move_backward(cub);
	if (keycode == KEY_D)
		return rotate_right(cub, 5);
	return (0);
}

int	key_anim(int keycode, t_cub *cub)
{
	if (keycode == 65513)
	{
		fire_anim(cub);
		//sleep(1);
		printf("iciok\n");
		//mlx_put_image_to_window(cub->mlx, cub->win, cub->texture->pistol->img, (W_WIDTH / 2) - (cub->texture->pistol->width / 2), W_HEIGHT - cub->texture->pistol->height - 65);
	}
	return (0);
}

int	mouse_track(int x, int y, t_cub *cub)
{
	if (cub->prev_mouse_x == 0)
		cub->prev_mouse_x = x;
	(void)y;
	//printf("%d, %d\n", x, cub->prev_mouse_x);
	if (x > cub->prev_mouse_x + 2)
		rotate_right(cub, 5);
	else if (x < cub->prev_mouse_x - 2)
		rotate_left(cub, 5);
	else
		return (0);
	cub->prev_mouse_x = x;
	return (0);
}
