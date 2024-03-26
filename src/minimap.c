/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:59:46 by francesco         #+#    #+#             */
/*   Updated: 2024/03/26 12:52:05 by francesco        ###   ########.fr       */
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
    x_max = (int)cub->player->map_x - 10;
    y_max = (int)cub->player->map_y - 10;
    printf("%d, %d\n", (int)cub->player->map_x, (int)cub->player->map_y);
    scale = 40 / (double)cub->minimap->width;
    //flag = 0;
    //printf("%d\n, %d\n", cub->minimap->width, cub->minimap->height);
    //printf("here: %p\n", cub->minimap->addr);
    while (y < cub->minimap->height - 1)
    {
        while (x < cub->minimap->width - 1)
        {
            if (check_if_null(cub->map, (int)y_max + (y * scale), (int)x_max - (int)(x_max - (x * scale))))
            {
                put_pixel(cub->minimap, x, y, convert_color(cub->floor));
               // flag = 1;
            }
            //if (flag == 0 && cub->map[(int)y_max - (int)(y * scale)][(int)x_max - (int)(x * scale)] == '0')
            //    put_pixel(cub->minimap, (int)x, (int)y, convert_color(cub->ceiling));
            //if (flag == 0 && cub->map[(int)(y_max - (int)(y * scale))][(int)x_max - (int)(x * scale)] == '1')
            //    put_pixel(cub->minimap, x, y, convert_color(cub->floor));
            //printf("%f", y);
            //printf("%d", (int)y_max - (int)(y * scale));
            //printf("here: %f", scale);
            //printf("%f", (double)y * (double)scale);
            x ++;
            // printf("%f, %f\n", x, y);
           // flag = 0;
        }
        x = 0;
        y++;
    }
    return (0);
}