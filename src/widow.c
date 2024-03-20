/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:37:13 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/20 19:50:12 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

int		clean_close(t_cub *cub)
{
	free_data(cub);
	exit(0);
	return (0);
}

void	init_window(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
	{
		ft_putstr_fd("Error\nmlx_init failed\n", 2);
		free_data(cub);
		exit(1);
	}
	cub->win = mlx_new_window(cub->mlx, W_WIDTH, W_HEIGHT, "Cub3D");
	if (!cub->win)
	{
		ft_putstr_fd("Error\nmlx_new_window failed\n", 2);
		free_data(cub);
		exit(1);
	}
}