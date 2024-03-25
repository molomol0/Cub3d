/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:51:52 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/25 20:36:26 by jdenis           ###   ########.fr       */
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
		my_mlx_pixel_put(cub,  ray->x -1, i++, convert_color(cub->floor));
	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(cub,  ray->x -1, i++, convert_color(cub->ceiling));
}

int	get_xpm_color(t_img *img, int x, int y, t_cub *cub)
{
	char	*dst;

	dst = img->addr + (((y * img->height) / cub->player->ray->wall_x) * img->line_length + ((x * img->width) / cub->player->ray->wall_y)* (img->bit_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int	get_color(t_cub *cub, int flag, int x, int y) // get the color of the wall
{
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x >= TILE_SIZE)
		x = TILE_SIZE - 1;
	if (y >= TILE_SIZE)
		y = TILE_SIZE - 1;
	// x = x % TILE_SIZE;
	// y = y % TILE_SIZE;
	if (flag == 0)
	{
		// return (0x00FF0000); // red
			// return get_xpm_color(cub->texture->we_img, x, y); // west wall
		// else
			return get_xpm_color(cub->texture->ea_img, x, y, cub); // east wall
	}
	else
	{
		// (void)cub;
		// return (0x0000FF00); // green
		// if ()
			// return get_xpm_color(cub->texture->so_img, x, y); // south wall
		// else
			return get_xpm_color(cub->texture->no_img, x, y, cub); // north wall
	}
}

void	draw_wall(t_cub *cub, t_ray *ray, int t_pix, int b_pix)
{
	int color;

	while (t_pix < b_pix)
	{
		color = get_color(cub, ray->side, ray->x - 1, t_pix);
		// printf("color = %d\n", color);
		my_mlx_pixel_put(cub, ray->x -1, t_pix, color);
		t_pix++;
	}
}

void	render_wall(t_cub *cub, t_ray *ray)
{
	double wall_h;
	double b_pix;
	double t_pix;

	wall_h = (W_HEIGHT / (ray->perp_dist / TILE_SIZE));
	ray->wall_x = wall_h;
	ray->wall_y = (W_WIDTH / (ray->perp_dist / TILE_SIZE));
	t_pix = -wall_h / 2 + W_HEIGHT / 2;
	b_pix = wall_h / 2 + W_HEIGHT / 2;
	if (b_pix > W_HEIGHT)
		b_pix = W_HEIGHT;
	if (t_pix < 0)
		t_pix = 0;
	draw_wall(cub, ray, t_pix, b_pix);
	draw_floor_ceiling(cub, ray, t_pix, b_pix);
}