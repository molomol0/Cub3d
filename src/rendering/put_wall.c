/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:51:52 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/02 14:29:48 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		pixel = img->addr + (y * img->line_length + x * (img->bit_per_pixel
					/ 8));
		if (pixel >= img->addr && pixel + sizeof(color) <= img->addr
			+ (img->height * img->line_length + img->width * (img->bit_per_pixel
					/ 8)))
		{
			*(int *)pixel = color;
		}
	}
}

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	if (x < 0)
		return ;
	put_pixel(cub->buff, x, y, color);
}

void	draw_floor_ceiling(t_cub *cub, t_ray *ray, int t_pix, int b_pix)
{
	int	i;

	i = b_pix;
	while (i < W_HEIGHT)
	{
		my_mlx_pixel_put(cub, ray->x - 1, i++, convert_color(cub->floor));
	}
	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(cub, ray->x - 1, i++, convert_color(cub->ceiling));
}

void	draw_wall(t_cub *cub, t_ray *ray, int t_pix, int b_pix)
{
	int	color;
	int	index;
	int	temp_t;

	index = 0;
	temp_t = t_pix;
	if (b_pix > W_HEIGHT)
		b_pix = W_HEIGHT;
	if (t_pix < 0)
		t_pix = 0;
	while (t_pix < b_pix)
	{
		color = get_color(cub, ray->side, index, temp_t);
		my_mlx_pixel_put(cub, ray->x - 1, t_pix, color);
		t_pix++;
		index++;
	}
}

void	render_wall(t_cub *cub, t_ray *ray)
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	wall_h = (W_HEIGHT / ray->perp_dist / 1.5);
	ray->wall_h = wall_h;
	ray->wall_w = (W_WIDTH / ray->perp_dist / 1.5);
	t_pix = -wall_h / 2 + W_HEIGHT / 2;
	b_pix = wall_h / 2 + W_HEIGHT / 2;
	draw_wall(cub, ray, t_pix, b_pix);
	draw_floor_ceiling(cub, ray, t_pix, b_pix);
}
