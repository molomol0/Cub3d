/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:51:59 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/01 10:50:35 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

int	convert_color(int *color)
{
	int	res;

	res = 0;
	res += color[0] << 16;
	res += color[1] << 8;
	res += color[2];
	return (res);
}

int	get_xpm_color(t_img *img, int y, t_cub *cub, int t_pix)
{
	cub->scale_y = ((double)img->height / (double)cub->player->ray->wall_h);
	if (t_pix < 0)
		y += (t_pix * -1);
	cub->scale_x = ((double)img->width / (double)cub->player->ray->wall_w);
	cub->real_y = (int)y * cub->scale_y;
	cub->real_x = (int)cub->player->ray->wall_w * cub->wall_x;
	cub->real_x *= cub->scale_x;
	cub->dst = (img->addr + (cub->real_y * img->line_length + (cub->real_x
					* (img->bit_per_pixel / 8))));
	return (*(unsigned int *)cub->dst);
}

int	get_color(t_cub *cub, int flag, int y, int t_pix)
{
	t_ray	*ray;

	(void)y;
	ray = cub->player->ray;
	if (ray->side == EAST || ray->side == WEST || ray->side == DOOR_EW)
		cub->wall_x = cub->player->map_y + ray->perp_dist * ray->raydir_y;
	else
		cub->wall_x = cub->player->map_x + ray->perp_dist * ray->raydir_x;
	cub->wall_x -= floor((cub->wall_x));
	if (flag == WEST)
		return (get_xpm_color(cub->texture->we_img, y, cub, t_pix));
	if (flag == SOUTH)
		return (get_xpm_color(cub->texture->so_img, y, cub, t_pix));
	if (flag == EAST)
		return (get_xpm_color(cub->texture->ea_img, y, cub, t_pix));
	if (flag == NORTH)
		return (get_xpm_color(cub->texture->no_img, y, cub, t_pix));
	if (flag == DOOR_NS || flag == DOOR_EW)
		return (get_xpm_color(cub->texture->door_img, y, cub,
				t_pix));
	return (0);
}
