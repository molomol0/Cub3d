/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:58:57 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/20 14:51:21 by jdenis           ###   ########.fr       */
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
		printf("A pressed\n");
	if (keycode == KEY_S)
		printf("S pressed\n");
	if (keycode == KEY_D)
		printf("D pressed\n");
	return (0);
}