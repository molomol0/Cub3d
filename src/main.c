/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:17:52 by ftholoza          #+#    #+#             */
/*   Updated: 2024/03/22 20:40:11 by francesco        ###   ########.fr       */
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
	printf ("%p\n", cub->map);
	if (map_check(cub->map) == 0)
	{
		free_data(cub);
		return (0);
	}
	player = player_struct_init(cub->map);
	cub->player = player;
	printf("p_dirx: %f\np_diry: %f\n", cub->player->dir_x, player->dir_y);
	printf("p_dirx: %f\np_diry: %f\n", player->pix_px, player->pix_py);
	printf("cam_plane_r: x: %f, y:%f\n",
		player->camera_plane_right_x, player->camera_plane_right_y);
	printf("cam_plane_l: x: %f, y:%f\n",
		player->camera_plane_left_x, player->camera_plane_left_y);
	print_data(cub);
	mlx_hook(cub->win, 17, 0, clean_close, cub);
	mlx_key_hook(cub->win, key_event, cub);
	ray_casting(cub, player);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->buff->img, 0, 0);
	mlx_key_hook(cub->win, key_event, cub);
	//free(player);
	mlx_loop(cub->mlx);
	free(player);
	free_data(cub);
	return (0);
}
