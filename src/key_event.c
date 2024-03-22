/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:58:57 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/22 20:41:30 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

int		key_event(int keycode, t_cub *cub)
{
	if (keycode == KEY_ESC)
		clean_close(cub);
	if (keycode == KEY_W)
		printf("W pressed\n");
	if (keycode == KEY_A)
	{
		printf("ok\n");
		printf("%fn", cub->player->dir_x);
		rotate_player(cub->player, -5);
		ray_casting(cub, cub->player);
		mlx_put_image_to_window(cub->mlx, cub->win, cub->buff->img, 0, 0);
	}
	if (keycode == KEY_S)
		printf("S pressed\n");
	if (keycode == KEY_D)
		printf("D pressed\n");
	return (0);
}
