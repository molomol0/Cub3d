/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:51:52 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/22 19:13:27 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;
	
	// img->width = W_WIDTH;
	// img->height = W_HEIGHT;
	// img->bit_per_pixel = 32;
	// img->line_length = img->width * (img->bit_per_pixel / 8);
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
	//else if (x >= W_WIDTH)
	//	return ;
	//if (y < 0)
	//	return ;
	//else if (y >= W_HEIGHT)
	//	return ;
	//mlx_pixel_put(cub->mlx, cub->win, x, y, color);
	put_pixel(cub->buff, x, y, color);
}

int		convert_color(int *color)
{
	int res;

	res = 0;
	res += color[0] << 16;
	res += color[1] << 8;
	res += color[2];
	return (res);
}

void	draw_floor_ceiling(t_cub *cub, t_ray *ray, int t_pix, int b_pix) // draw the floor and the ceiling
{
	int i;

	i = b_pix;
	while (i < W_HEIGHT)
		my_mlx_pixel_put(cub,  ray->x / ray->scale - 1, i++, convert_color(cub->floor));
	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(cub,  ray->x / ray->scale - 1, i++, convert_color(cub->ceiling));
}

int	get_color(t_cub *cub, int flag) // get the color of the wall
{
	(void)cub;
	if (flag == 0)
	{
		// if (cub->ray->ray_ngl > M_PI / 2 && cub->ray->ray_ngl < 3 * (M_PI / 2))
			return (0xB5B5B5FF); // west wall
		// else
		// 	return (0xB5B5B5FF); // east wall
	}
	else
	{
		// if (cub->ray->ray_ngl > 0 && cub->ray->ray_ngl < M_PI)
			return (0xF5F5F5FF); // south wall
		// else
		// 	return (0xF5F5F5FF); // north wall
	}
}

void	draw_wall(t_cub *cub, t_ray *ray, int t_pix, int b_pix)
{
	int color;

	color = get_color(cub, ray->side);
	while (t_pix < b_pix)
		my_mlx_pixel_put(cub, (ray->x / ray->scale), t_pix++, color);
}

void	render_wall(t_cub *cub, t_ray *ray)
{
	double wall_h;
	double b_pix;
	double t_pix;

	wall_h = (W_HEIGHT / (ray->perp_dist / TILE_SIZE));
	// b_pix = -wall_h / 2 + W_HEIGHT / 2;
	// t_pix = wall_h / 2 + W_HEIGHT / 2;
	t_pix = -wall_h / 2 + W_HEIGHT / 2;
	b_pix = wall_h / 2 + W_HEIGHT / 2;
	if (b_pix > W_HEIGHT)
		b_pix = W_HEIGHT;
	if (t_pix < 0)
		t_pix = 0;
	printf("wall_h: %f\n", wall_h);
	//printf("t_pix: %f, b_pix: %f\n", t_pix, b_pix);
	draw_wall(cub, ray, t_pix, b_pix);
	draw_floor_ceiling(cub, ray, t_pix, b_pix);
}