/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:28:40 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/29 17:51:33 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

int	get_pix_color(t_img *img, int x, int y)
{
	char	*dst;

	dst = (img->addr + (y * img->line_length + (x * (img->bit_per_pixel / 8))));
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
	while (j < img->height)
	{
		while (i < img->width)
		{
			if (get_pix_color(img, i, j) != -16777216)
				put_pixel(cub->buff, temp, y, get_pix_color(img, i, j));
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

void	animation(t_cub *cub)
{
	if (cub->on_of == 1)
	{
		if (cub->frame_start == 0)
		{
			cub->frame_start++;
			cub->anim_start = ft_get_start();
		}
		if (ft_gettime(cub->anim_start) < 100)
			put_first_frame(cub);
		if (ft_gettime(cub->anim_start) >= 150)
			put_middle_frame(cub, cub->texture->pistol_r1);
		if (ft_gettime(cub->anim_start) > 200)
			put_middle_frame(cub, cub->texture->pistol_r2);
		if (ft_gettime(cub->anim_start) > 250)
		{
			put_last_frame(cub);
			return ;
		}
	}
}
