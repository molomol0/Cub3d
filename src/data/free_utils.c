/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:55:09 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/02 18:10:09 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

void	free_sn(t_cub *cub)
{
	if (cub->texture->no)
		free(cub->texture->no);
	if (cub->mlx && cub->texture->no_img->img)
		mlx_destroy_image(cub->mlx, cub->texture->no_img->img);
	if (cub->texture->no_img)
		free(cub->texture->no_img);
	if (cub->texture->so)
		free(cub->texture->so);
	if (cub->mlx && cub->texture->so_img->img)
		mlx_destroy_image(cub->mlx, cub->texture->so_img->img);
	if (cub->texture->so_img)
		free(cub->texture->so_img);
}

void	free_ew(t_cub *cub)
{
	if (cub->texture->we)
		free(cub->texture->we);
	if (cub->mlx && cub->texture->we_img->img)
		mlx_destroy_image(cub->mlx, cub->texture->we_img->img);
	if (cub->texture->we_img)
		free(cub->texture->we_img);
	if (cub->texture->ea)
		free(cub->texture->ea);
	if (cub->mlx && cub->texture->ea_img->img)
		mlx_destroy_image(cub->mlx, cub->texture->ea_img->img);
	if (cub->texture->ea_img)
		free(cub->texture->ea_img);
}

void	free_pistol_first(t_cub *cub)
{
	if (cub->texture->pi)
		free(cub->texture->pi);
	if (cub->mlx && cub->texture->pistol->img)
		mlx_destroy_image(cub->mlx, cub->texture->pistol->img);
	if (cub->texture->pistol)
		free(cub->texture->pistol);
	if (cub->texture->pif)
		free(cub->texture->pif);
	if (cub->mlx && cub->texture->pistol_flame->img)
		mlx_destroy_image(cub->mlx, cub->texture->pistol_flame->img);
	if (cub->texture->pistol_flame)
		free(cub->texture->pistol_flame);
	if (cub->texture->pir1)
		free(cub->texture->pir1);
	if (cub->mlx && cub->texture->pistol_r1->img)
		mlx_destroy_image(cub->mlx, cub->texture->pistol_r1->img);
	if (cub->texture->pistol_r1)
		free(cub->texture->pistol_r1);
}

void	free_pistol_door(t_cub *cub)
{
	if (cub->texture->pir2)
		free(cub->texture->pir2);
	if (cub->mlx && cub->texture->pistol_r2->img)
		mlx_destroy_image(cub->mlx, cub->texture->pistol_r2->img);
	if (cub->texture->pistol_r2)
		free(cub->texture->pistol_r2);
	if (cub->texture->door)
		free(cub->texture->door);
	if (cub->mlx && cub->texture->door_img->img)
		mlx_destroy_image(cub->mlx, cub->texture->door_img->img);
	if (cub->texture->door_img)
		free(cub->texture->door_img);
}

void	free_texture(t_cub *cub)
{
	if (cub && cub->texture)
	{
		free_sn(cub);
		free_ew(cub);
		free_pistol_first(cub);
		free_pistol_door(cub);
	}
	free(cub->texture);
}
