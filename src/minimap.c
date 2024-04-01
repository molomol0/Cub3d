/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:59:46 by francesco         #+#    #+#             */
/*   Updated: 2024/04/01 09:26:46 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	init_minimap_t(t_cub *cub)
{
	cub->minimap_t->x = 0;
	cub->minimap_t->y = 0;
	cub->minimap_t->x_max = (int)cub->player->map_x - 20;
	cub->minimap_t->y_max = (int)cub->player->map_y - 20;
	cub->minimap_t->scale_x = 40 / (double)cub->minimap->width;
	cub->minimap_t->scale_y = 40 / (double)cub->minimap->height;
}

void	player_icon(t_cub *cub)
{
	t_minimap	*map;

	map = cub->minimap_t;
	put_pixel(cub->minimap, map->x_pos,
		map->y_pos, create_trgb(0, 205, 92, 92));
	put_pixel(cub->minimap, map->x_pos,
		map->y_pos + 1, create_trgb(0, 205, 92, 92));
	put_pixel(cub->minimap, map->x_pos + 1,
		map->y_pos, create_trgb(0, 205, 92, 92));
	put_pixel(cub->minimap, map->x_pos + 1,
		map->y_pos + 1, create_trgb(0, 205, 92, 92));
}

void	minimap_pixel_draw(t_cub *cub)
{
	t_minimap	*map;

	map = cub->minimap_t;
	if (check_if_null(cub->map, map->x_max + map->x * map->scale_x,
			map->y_max + map->y * map->scale_y))
		put_pixel(cub->minimap, map->x, map->y, create_trgb(0, 0, 0, 0));
	else if (cub->map[(int)(map->y_max + map->y * map->scale_y)]
		[(int)(map->x_max + map->x * map->scale_x)] == '1')
		put_pixel(cub->minimap, map->x, map->y, create_trgb(0, 69, 69, 69));
	else
		put_pixel(cub->minimap, map->x, map->y, create_trgb(0, 255, 255, 255));
	if ((roundf(map->x_max + map->x * map->scale_x) == cub->player->ray->map_x)
		&& (roundf(map->y_max + map->y * map->scale_y)
			== cub->player->ray->map_y))
	{
		map->x_pos = map->x;
		map->y_pos = map->y;
	}
}

int	draw_minimap(t_cub *cub)
{
	t_minimap	*map;

	map = cub->minimap_t;
	init_minimap_t(cub);
	while (map->y < cub->minimap->height - 1)
	{
		while (map->x < cub->minimap->width - 1)
		{
			minimap_pixel_draw(cub);
			map->x++;
		}
		map->x = 0;
		map->y++;
	}
	player_icon(cub);
	return (0);
}
