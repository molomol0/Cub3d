/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:44:13 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/02 18:29:13 by jdenis           ###   ########.fr       */
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
	if (key == KEY_ALT)
		cub->on_of = 1;
	if (key == KEY_E)
		check_doors(cub);
	if (key == KEY_SHIFT)
		cub->player->speed *= 2;
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
	if (key == KEY_SHIFT)
		cub->player->speed /= 2;
	return (0);
}
