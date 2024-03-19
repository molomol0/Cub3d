/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:17:52 by ftholoza          #+#    #+#             */
/*   Updated: 2024/03/19 18:16:50 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_cub	*cub;

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
	print_data(cub);
	init_window(cub);
	mlx_hook(cub->win, 17, 0, clean_close, cub);
	mlx_key_hook(cub->win, key_event, cub);
	mlx_loop(cub->mlx);
	free_data(cub);
	return (0);
}
