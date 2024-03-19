/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:17:52 by ftholoza          #+#    #+#             */
/*   Updated: 2024/03/19 19:57:08 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_cub		*cub;
	t_player	*player;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		return (1);
	}
	cub = init_data(argv);
	if (!cub)
		return (1);
	if (map_check(cub->map) == 0)
	{
		free_data(cub);
		return (0);
	}
	player = player_struct_init(cub->map);
	printf("pos_x: %f, pos_y: %f\ndir_x %f, dir_y %f\nleft_cam: x:%f, y:%f\nright_cam: x: %f, y: %f\n", player->pos_x, player->pos_y, player->dir_x, player->dir_y, player->camera_plane_left_x, player->camera_plane_left_y, player->camera_plane_right_x, player->camera_plane_right_y);
	free(player);
	print_data(cub);
	init_window(cub);
	mlx_hook(cub->win, 17, 0, clean_close, cub);
	mlx_key_hook(cub->win, key_event, cub);
	mlx_loop(cub->mlx);
	free_data(cub);
	return (0);
}
