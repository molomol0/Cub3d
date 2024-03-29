/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:51:24 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/29 17:51:42 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

void	put_first_frame(t_cub *cub)
{
	ray_casting(cub, cub->player);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->buff->img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->minimap->img, 0,
		0);
	my_put_img_to_buff(cub->texture->pistol_flame, (W_WIDTH / 2)
		- (cub->texture->pistol_flame->width / 2), W_HEIGHT
		- cub->texture->pistol_flame->height, cub);
}

void	put_middle_frame(t_cub *cub, t_img *img)
{
	ray_casting(cub, cub->player);
	my_put_img_to_buff(img, (W_WIDTH / 2)
		- (img->width / 2), W_HEIGHT
		- img->height, cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->buff->img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->minimap->img, 0,
		0);
}

void	put_last_frame(t_cub *cub)
{
	ray_casting(cub, cub->player);
	my_put_img_to_buff(cub->texture->pistol, (W_WIDTH / 2)
		- (cub->texture->pistol->width / 2), W_HEIGHT
		- cub->texture->pistol->height, cub);
	cub->frame_start = 0;
	cub->on_of = 0;
}
