/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:58:57 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/01 09:55:51 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

int	open_close(int i, int j, t_cub *cub)
{
	if (cub->map[j][i] == '4')
	{
		cub->map[j][i] = '3';
		return (1);
	}
	if (cub->map[j][i] == '3')
	{
		cub->map[j][i] = '4';
		return (1);
	}
	return (0);
}

void	check_doors(t_cub *cub)
{
	int	i;
	int	j;
	int	temp_i;
	int	temp_j;

	i = cub->player->map_x - 1;
	j = cub->player->map_y - 1;
	temp_j = j;
	temp_i = i;
	while (j < temp_j + 3)
	{
		while (i < temp_i + 3)
		{
			if (i == cub->player->ray->map_x && j == cub->player->ray->map_y)
				i++;
			if (check_if_null(cub->map, i, j))
				i++;
			open_close(i, j, cub);
			i++;
		}
		i = temp_i;
		j++;
	}
	return ;
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
	if (x > cub->prev_mouse_x)
		rotate_right(cub, 2);
	else if (x < cub->prev_mouse_x)
		rotate_left(cub, 2);
	else
		return (0);
	cub->prev_mouse_x = x;
	return (0);
}
