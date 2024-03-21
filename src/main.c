/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:17:52 by ftholoza          #+#    #+#             */
/*   Updated: 2024/03/21 00:31:19 by francesco        ###   ########.fr       */
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
	//free(player);
	print_data(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->texture->no_img, 0, 0);
	mlx_hook(cub->win, 17, 0, clean_close, cub);
	mlx_key_hook(cub->win, key_event, cub);
	for (int i = 0; i < 10; i++)
	{
		printf("test here\n");
		rotate_player(player, 5);
	}
	free(player);
	mlx_loop(cub->mlx);
	free_data(cub);
	return (0);
}
