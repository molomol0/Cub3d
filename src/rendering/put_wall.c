/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:51:52 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/27 02:49:49 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;
	
	//printf("here: %d\n", x);
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
		my_mlx_pixel_put(cub,  ray->x -1, i++, convert_color(cub->ceiling));
	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(cub,  ray->x -1, i++, create_trgb(0, 0, 0, 0));
}

int	get_xpm_color(t_img *img, int x, int y, t_cub *cub, double wall_x)
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
	scale_x = ((double)img->width / (double)cub->player->ray->wall_w);
	real_y = (int)y * scale_y;
	real_x = (int)cub->player->ray->wall_w * (double)wall_x;
	real_x *= scale_x;
	dst = (img->addr + (real_y * img->line_length + (real_x * (img->bit_per_pixel / 8))));
	return (*(unsigned int *)dst);
}

int	get_color(t_cub *cub, int flag, int x, int y) // get the color of the wall
{
	t_ray	*ray;
	double	wall_x;
	(void)y;

	ray = cub->player->ray;
    if (ray->side == 0)
		wall_x =  cub->player->map_y + ray->perp_dist * ray->raydir_y;
    else
		wall_x =  cub->player->map_x + ray->perp_dist * ray->raydir_x;
    wall_x -= floor((wall_x));
	if (flag == 0)
		return get_xpm_color(cub->texture->we_img, x, y, cub, wall_x);
	else
		return get_xpm_color(cub->texture->we_img, x, y, cub, wall_x);
}

void	draw_wall(t_cub *cub, t_ray *ray, int t_pix, int b_pix)
{
	int color;
	int	index;

	index = 0;
	while (t_pix < b_pix)
	{
		color = get_color(cub, ray->side, ray->x - 1, index);
		my_mlx_pixel_put(cub, ray->x -1, t_pix, color);
		t_pix++;
		index++;
	}
}

void	render_wall(t_cub *cub, t_ray *ray)
{
	double wall_h;
	double b_pix;
	double t_pix;

	wall_h = (W_HEIGHT / ray->perp_dist / 1.5);
	ray->wall_h = wall_h;
	ray->wall_w = (W_WIDTH / ray->perp_dist / 1.5);
	t_pix = -wall_h / 2 + W_HEIGHT / 2;
	b_pix = wall_h / 2 + W_HEIGHT / 2;
	if (b_pix > W_HEIGHT)
		b_pix = W_HEIGHT;
	if (t_pix < 0)
		t_pix = 0;
	draw_wall(cub, ray, t_pix, b_pix);
	draw_floor_ceiling(cub, ray, t_pix, b_pix);
}