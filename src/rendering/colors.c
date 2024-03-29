/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:51:59 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/29 19:03:29 by jdenis           ###   ########.fr       */
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

int	get_xpm_color(t_img *img, int x, int y, t_cub *cub, double wall_x,
		int t_pix)
{
	char	*dst;
	double	scale_y;
	double	scale_x;
	int		real_y;
	int		real_x;

	(void)x;
	(void)y;
	(void)cub;
	scale_y = ((double)img->height / (double)cub->player->ray->wall_h);
	if (t_pix < 0)
		y += (t_pix * -1);
	scale_x = ((double)img->width / (double)cub->player->ray->wall_w);
	real_y = (int)y * scale_y;
	real_x = (int)cub->player->ray->wall_w * (double)wall_x;
	real_x *= scale_x;
	dst = (img->addr + (real_y * img->line_length + (real_x
					* (img->bit_per_pixel / 8))));
	return (*(unsigned int *)dst);
}

int	get_color(t_cub *cub, int flag, int x, int y, int t_pix)
{
	t_ray	*ray;
	double	wall_x;

	(void)y;
	ray = cub->player->ray;
	if (ray->side == 0)
		wall_x = cub->player->map_y + ray->perp_dist * ray->raydir_y;
	else
		wall_x = cub->player->map_x + ray->perp_dist * ray->raydir_x;
	wall_x -= floor((wall_x));
	if (flag == 0)
		return (get_xpm_color(cub->texture->so_img, x, y, cub, wall_x, t_pix));
	else
		return (get_xpm_color(cub->texture->we_img, x, y, cub, wall_x, t_pix));
}
