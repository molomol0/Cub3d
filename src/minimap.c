/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:59:46 by francesco         #+#    #+#             */
/*   Updated: 2024/03/26 18:53:24 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub_struct.h"
# include "cub.h"

int draw_minimap(t_cub *cub)
{
    double  x;
    double  y;
    double  x_max;
    double  y_max;
    double  scale;
    //int     flag;

    x = 0;
    y = 0;
    x_max = (int)cub->player->map_x - 15;
    y_max = (int)cub->player->map_y - 15;
    printf("%f, %f\n", x_max, y_max);
    printf("%d, %d\n", (int)cub->player->map_x, (int)cub->player->map_y);
    scale = 30 / (double)cub->minimap->width;
    //printf("%d\n, %d\n", cub->minimap->width, cub->minimap->height);
    //printf("here: %p\n", cub->minimap->addr);
    while (y < cub->minimap->height - 1)
    {
        while (x < cub->minimap->width - 1)
        {
            if (check_if_null(cub->map, y_max + y * scale, x_max + x * scale))
            {
                put_pixel(cub->minimap, x, y, convert_color(cub->floor));
               // flag = 1;
            }
            else
            {
                put_pixel(cub->minimap, x, y, convert_color(cub->ceiling));
            }
            x ++;
        }
        //printf("%f\n", x_max + x * scale);
        //x_max = (int)cub->player->map_x - 15;
        x = 0;
        y++;
    }
    return (0);
}