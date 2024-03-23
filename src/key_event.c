/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:58:57 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/23 15:40:03 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

int		key_event(int keycode, t_cub *cub)
{
	printf("%d\n", keycode);
	if (keycode == KEY_ESC)
		clean_close(cub);
	if (keycode == KEY_W)
	{
		printf("ok\n");
		//cub->player->map_y += 0.1;
		cub->player->pos_x += cub->player->dir_x * 10;
		cub->player->pos_y += cub->player->dir_y * 10;
		cub->player->map_x = cub->player->pos_x / 100;
		cub->player->map_y = cub->player->pos_y / 100;
		ray_casting(cub, cub->player);
		mlx_put_image_to_window(cub->mlx, cub->win, cub->buff->img, 0, 0);
	}
	printf("W pressed\n");
	if (keycode == KEY_A)
	{
		printf("ok\n");
	}
	if (keycode == KEY_S)
		printf("S pressed\n");
	if (keycode == KEY_D)
		printf("D pressed\n");
	if (keycode == 65363)
	{
		rotate_player(cub->player, 5);
		ray_casting(cub, cub->player);
		mlx_put_image_to_window(cub->mlx, cub->win, cub->buff->img, 0, 0);
	}
	if (keycode == 65361)
	{
		rotate_player(cub->player, -5);
		ray_casting(cub, cub->player);
		mlx_put_image_to_window(cub->mlx, cub->win, cub->buff->img, 0, 0);
	}
	return (0);
}
