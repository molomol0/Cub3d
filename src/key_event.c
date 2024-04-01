/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:58:57 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/01 01:39:11 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

void	check_doors(t_cub *cub)
{
	int	i;
	int	j;
	int	limit_i;
	int	limit_j;
	int	temp;
	
	i = cub->player->map_x - 1;
	j = cub->player->map_y - 1;
	limit_i = i + 3;
	limit_j = j + 3;
	temp = i;
	while (j < limit_j)
	{	
		while (i < limit_i)
		{
			//printf("%c\n", cub->map[j][i]);
			if (i == cub->player->ray->map_x && j == cub->player->ray->map_y)
				i++;
			if (check_if_null(cub->map, i, j))
				i++;
			if (cub->map[j][i] == '4')
			{
				cub->map[j][i] = '3';
				return ;
			}
			if (cub->map[j][i] == '3')
			{
				cub->map[j][i] = '4';
				return ;
			}
			i++;
		}
		i = temp;
		j++;
	}
	return ;
}

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
		||cub->map[(int)map_y][(int)map_x]  == '3')
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
		||cub->map[(int)map_y][(int)map_x]  == '3')
		return (0);
	return (1);
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
