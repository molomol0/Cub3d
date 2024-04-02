/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:17:52 by ftholoza          #+#    #+#             */
/*   Updated: 2024/04/02 15:48:03 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

void	main_loop(t_cub	*cub)
{
	mlx_hook(cub->win, 17, 0, clean_close, cub);
	mlx_hook(cub->win, 6, 1l << 6, mouse_track, cub);
	mlx_mouse_hook(cub->win, mouse_event, cub);
	mlx_loop_hook(cub->mlx, game_run, cub);
	mlx_hook(cub->win, KeyPress, KeyPressMask, check_press, cub);
	mlx_hook(cub->win, KeyRelease, KeyReleaseMask, check_release, cub);
	mlx_loop(cub->mlx);
}

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
	cub->start_time = ft_get_start();
	player = player_struct_init(cub->map);
	cub->player = player;
	main_loop(cub);
	free_data(cub);
	return (0);
}

int	game_run(t_cub *cub)
{
	double	frame_time;
	char	*tmp;

	do_move(cub);
	cub->current_time = ft_gettime(cub->start_time);
	frame_time = ((double)cub->current_time - (double)cub->old_time) / 1000;
	ray_casting(cub, cub->player);
	draw_minimap(cub);
	my_put_img_to_buff(cub->texture->pistol, (W_WIDTH / 2)
		- (cub->texture->pistol->width / 2), W_HEIGHT
		- cub->texture->pistol->height, cub);
	animation(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->buff->img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->minimap->img, 0, 0);
	tmp = ft_itoa((int)(1 / frame_time));
	mlx_string_put(cub->mlx, cub->win, 0, 10,
		create_trgb(0, 255, 0, 0), tmp);
	free(tmp);
	cub->old_time = cub->current_time;
	return (0);
}
