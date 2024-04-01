/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:55:09 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/01 10:31:30 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

int	wall_pistol(t_cub *cub)
{
	if (malloc_texture(cub) == -1)
	{
		free(cub);
		return (-1);
	}
	if (malloc_pistol(cub) == -1)
	{
		free_texture(cub);
		free(cub);
		return (-1);
	}
	return (0);
}

int	null_init_check(t_cub *cub, char **argv)
{
	null_init(cub);
	if (travel_file(argv[1], cub) == -1 || check_data(cub) == -1)
	{
		free_data(cub);
		return (-1);
	}
	init_window(cub);
	if (init_buff_minimap(cub) == -1)
	{
		free_data(cub);
		return (-1);
	}
	return (0);
}

t_cub	*init_data(char **argv)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	if (!cub)
	{
		ft_putstr_fd("Error\nMalloc failed\n", 2);
		return (NULL);
	}
	if (wall_pistol(cub) == -1)
		return (NULL);
	cub->minimap_t = malloc(sizeof(t_minimap));
	if (!cub->minimap_t)
	{
		ft_putstr_fd("Error\nMalloc failed\n", 2);
		return (NULL);
	}
	if (null_init_check(cub, argv) == -1)
		return (NULL);
	get_texture(cub);
	return (cub);
}

void	free_img(t_img *img, void *mlx)
{
	if (img)
	{
		mlx_destroy_image(mlx, img->img);
		free(img);
	}
}

void	free_data(t_cub *cub)
{
	free_texture(cub);
	if (cub->map)
		free_strs(cub->map);
	if (cub->minimap_t)
		free(cub->minimap_t);
	if (cub->player)
	{
		if (cub->player->ray)
			free(cub->player->ray);
		free(cub->player);
	}
	free_img(cub->minimap, cub->mlx);
	free_img(cub->buff, cub->mlx);
	if (cub->mlx && cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->mlx)
	{
		mlx_loop_end(cub->mlx);
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
	}
	free(cub);
}

// void	print_data(t_cub *cub)
// {
// 	int	i;

// 	ft_putstr_fd("NO: ", 1);
// 	(ft_putstr_fd(cub->texture->no, 1), ft_putstr_fd("\n", 1));
// 	ft_putstr_fd("SO: ", 1);
// 	(ft_putstr_fd(cub->texture->so, 1), ft_putstr_fd("\n", 1));
// 	ft_putstr_fd("WE: ", 1);
// 	(ft_putstr_fd(cub->texture->we, 1), ft_putstr_fd("\n", 1));
// 	ft_putstr_fd("EA: ", 1);
// 	(ft_putstr_fd(cub->texture->ea, 1), ft_putstr_fd("\n", 1));
// 	printf("PISTOL0: %s\n", cub->texture->pi);
// 	//printf("PISTOL1: %s\n", cub->texture->pif);
// 	//printf("PISTOL2: %s\n", cub->texture->pir1);
// 	//printf("PISTOL3: %s\n", cub->texture->pir2);

// 	(ft_putstr_fd("F: ", 1), ft_putnbr_fd(cub->floor[0], 1));
// 	(ft_putstr_fd(",", 1), ft_putnbr_fd(cub->floor[1], 1));
// 	ft_putstr_fd(",", 1);
// 	(ft_putnbr_fd(cub->floor[2], 1), ft_putstr_fd("\n", 1));
// 	(ft_putstr_fd("C: ", 1), ft_putnbr_fd(cub->ceiling[0], 1));
// 	(ft_putstr_fd(",", 1), ft_putnbr_fd(cub->ceiling[1], 1));
// 	ft_putstr_fd(",", 1);
// 	(ft_putnbr_fd(cub->ceiling[2], 1), ft_putstr_fd("\n", 1));
// 	ft_putstr_fd("Map:\n", 1);
// 	i = 0;
// 	while (cub->map[i])
// 	{
// 		(ft_putstr_fd(cub->map[i], 1), ft_putstr_fd("\n", 1));
// 		i++;
// 	}
// }
