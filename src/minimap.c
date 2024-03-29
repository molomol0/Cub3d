/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:59:46 by francesco         #+#    #+#             */
/*   Updated: 2024/03/29 18:01:46 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	draw_minimap(t_cub *cub)
{
	double	x;
	double	y;
	double	x_max;
	double	y_max;
	double	scale_x;
	double	scale_y;
	double	x_pos;
	double	y_pos;

	x = 0;
	y = 0;
	x_max = (int)cub->player->map_x - 20;
	y_max = (int)cub->player->map_y - 20;
	scale_x = 40 / (double)cub->minimap->width;
	scale_y = 40 / (double)cub->minimap->height;
	while (y < cub->minimap->height - 1)
	{
		while (x < cub->minimap->width - 1)
		{
			if (check_if_null(cub->map, x_max + x * scale_x, y_max + y
					* scale_y))
			{
				put_pixel(cub->minimap, x, y, create_trgb(0, 0, 0, 0));
			}
			else if (cub->map[(int)(y_max + y * scale_y)][(int)(x_max + x
						* scale_x)] == '1')
			{
				put_pixel(cub->minimap, x, y, create_trgb(0, 69, 69, 69));
			}
			else
			{
				put_pixel(cub->minimap, x, y, create_trgb(0, 255, 255, 255));
			}
			if ((roundf(x_max + x * scale_x) == cub->player->ray->map_x)
				&& (roundf(y_max + y * scale_y) == cub->player->ray->map_y))
			{
				x_pos = x;
				y_pos = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
	put_pixel(cub->minimap, x_pos, y_pos, create_trgb(0, 205, 92, 92));
	put_pixel(cub->minimap, x_pos, y_pos + 1, create_trgb(0, 205, 92, 92));
	put_pixel(cub->minimap, x_pos + 1, y_pos, create_trgb(0, 205, 92, 92));
	put_pixel(cub->minimap, x_pos + 1, y_pos + 1, create_trgb(0, 205, 92, 92));
	return (0);
}
