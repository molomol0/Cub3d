/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:17:52 by ftholoza          #+#    #+#             */
/*   Updated: 2024/03/29 15:13:34 by jdenis           ###   ########.fr       */
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
	cub->start_time = ft_get_start();
	cub->frame_start = 0;
	cub->old_time = 0;
	player = player_struct_init(cub->map);
	cub->player = player;
	// print_data(cub);
	mlx_hook(cub->win, 17, 0, clean_close, cub);
	mlx_hook(cub->win, 6, 1l << 6, mouse_track, cub);
	mlx_key_hook(cub->win, key_anim, cub);
	mlx_mouse_hook(cub->win, mouse_event, cub);
	mlx_loop_hook(cub->mlx, game_run, cub);
	mlx_hook(cub->win, KeyPress, KeyPressMask, check_press, cub);
	mlx_hook(cub->win, KeyRelease, KeyReleaseMask, check_release, cub);
	mlx_loop(cub->mlx);
	free(player);
	free_data(cub);
	return (0);
}

int		get_pix_color(t_img *img, int x, int y)
{
	char	*dst;

	dst = (img->addr + (y * img->line_length
				+ (x * (img->bit_per_pixel / 8))));
	return (*(unsigned int *)dst);
}

void	my_put_img_to_buff(t_img *img, int x, int y, t_cub *cub)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	temp = x;
	//printf("%d, %d\n", img->height, img->width);
	while (j < img->height)
	{
		while (i < img->width)
		{
			if (get_pix_color(img, i, j) != -16777216)
				put_pixel(cub->buff, temp, y, get_pix_color(img, i, j));
			//if (i == 0)
			//	printf("%d\n", get_pix_color(cub->texture->pistol, i, j));
			i++;
			temp++;
		}
		i = 0;
		temp = x;
		j++;
		y++;
	}
	return ;
}

void	animation(t_cub	*cub)
{
	if (cub->on_of == 1)
	{
		if (cub->frame_start == 0)
		{
			cub->frame_start++;
			cub->anim_start = ft_get_start();
		}
		if (ft_gettime(cub->anim_start) < 100)
		{
			ray_casting(cub, cub->player);
			mlx_put_image_to_window(cub->mlx, cub->win, cub->buff->img, 0, 0);
			mlx_put_image_to_window(cub->mlx, cub->win, cub->minimap->img, 0, 0);
			my_put_img_to_buff(cub->texture->pistol_flame, (W_WIDTH / 2)
				- (cub->texture->pistol_flame->width / 2),
				W_HEIGHT - cub->texture->pistol_flame->height, cub);
		}
		if (ft_gettime(cub->anim_start) >= 150)
		{
			ray_casting(cub, cub->player);
			my_put_img_to_buff(cub->texture->pistol_r1, (W_WIDTH / 2)
				- (cub->texture->pistol_r1->width / 2),
				W_HEIGHT - cub->texture->pistol_r1->height, cub);
			mlx_put_image_to_window(cub->mlx, cub->win, cub->buff->img, 0, 0);
			mlx_put_image_to_window(cub->mlx, cub->win, cub->minimap->img, 0, 0);
		}
		if (ft_gettime(cub->anim_start) > 200)
		{
			ray_casting(cub, cub->player);
			my_put_img_to_buff(cub->texture->pistol_r2, (W_WIDTH / 2)
				- (cub->texture->pistol_r2->width / 2),
				W_HEIGHT - cub->texture->pistol_r2->height, cub);
			mlx_put_image_to_window(cub->mlx, cub->win, cub->buff->img, 0, 0);
			mlx_put_image_to_window(cub->mlx, cub->win, cub->minimap->img, 0, 0);
		}
		if (ft_gettime(cub->anim_start) > 250)
		{
			ray_casting(cub, cub->player);
			my_put_img_to_buff(cub->texture->pistol, (W_WIDTH / 2)
				- (cub->texture->pistol->width / 2),
				W_HEIGHT - cub->texture->pistol->height, cub);
			cub->frame_start = 0;
			cub->on_of = 0;
			return ;
		}
	}
}

int	game_run(t_cub	*cub)
{
	double	frame_time;

	do_move(cub);
	cub->current_time = ft_gettime(cub->start_time);
	frame_time = ((double)cub->current_time - (double)cub->old_time) / 1000;
	ray_casting(cub, cub->player);
	draw_minimap(cub);
	my_put_img_to_buff(cub->texture->pistol, (W_WIDTH / 2)
		- (cub->texture->pistol->width / 2),
		W_HEIGHT - cub->texture->pistol->height, cub);
	animation(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->buff->img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->minimap->img, 0, 0);
	mlx_string_put(cub->mlx, cub->win, 0, 10, create_trgb(0, 255, 255, 255), ft_itoa((int)(1 / frame_time)));
	cub->old_time = cub->current_time;
	return (0);
}
