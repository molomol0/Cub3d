/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:55:09 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/27 02:29:00 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"
#include "mlx.h"

int	check_data(t_cub *cub)
{
	if (cub->texture->no == NULL || cub->texture->so == NULL
		|| cub->texture->we == NULL || cub->texture->ea == NULL
		|| cub->floor[0] == -1 || cub->ceiling[0] == -1 || cub->map == NULL)
	{
		ft_putstr_fd("Error\nMissing data\n", 2);
		return (-1);
	}
	return (0);
}

void	null_init(t_cub *cub)
{
	cub->texture->no = NULL;
	cub->texture->so = NULL;
	cub->texture->we = NULL;
	cub->texture->ea = NULL;
	cub->floor[0] = -1;
	cub->ceiling[0] = -1;
	cub->prev_mouse_x = 0;
	cub->map = NULL;
	cub->mlx = NULL;
	cub->win = NULL;
	cub->buff = NULL;
	cub->minimap = NULL;
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
	cub->player = malloc(sizeof(t_player));
	cub->texture = malloc(sizeof(t_texture));
	if (!cub->texture)
	{
		ft_putstr_fd("Error\nMalloc failed\n", 2);
		return (NULL);
	}
	cub->texture->no_img = malloc(sizeof(t_img));
	cub->texture->so_img = malloc(sizeof(t_img));
	cub->texture->we_img = malloc(sizeof(t_img));
	cub->texture->ea_img = malloc(sizeof(t_img));
	null_init(cub);
	if (travel_file(argv[1], cub) == -1 || check_data(cub) == -1)
	{
		free_data(cub);
		return (NULL);
	}
	init_window(cub);
	cub->buff = malloc(sizeof(t_img));
	cub->minimap = malloc(sizeof(t_img));
	cub->minimap->img = mlx_new_image(cub->mlx, W_WIDTH / 5, W_HEIGHT / 5);
	cub->minimap->width = W_WIDTH / 5;
	cub->minimap->height = W_HEIGHT / 5;
	//cub->minimap->bit_per_pixel = 4;
	//cub->minimap->line_length = 4 * cub->minimap->width;
	cub->minimap->addr = mlx_get_data_addr(cub->minimap->img, &cub->minimap->bit_per_pixel, &cub->minimap->line_length, &cub->minimap->endian);
	cub->buff->img = mlx_new_image(cub->mlx, W_WIDTH, W_HEIGHT);
	cub->buff->width = W_WIDTH;
	cub->buff->height = W_HEIGHT;
	cub->buff->addr = mlx_get_data_addr(cub->buff->img, &cub->buff->bit_per_pixel, &cub->buff->line_length, &cub->buff->endian);
	get_texture(cub);
	return (cub);
}

void	free_data(t_cub *cub)
{
	if (cub && cub->texture)
	{
		if (cub->texture->no)
			free(cub->texture->no);
		if (cub->texture->so)
			free(cub->texture->so);
		if (cub->texture->we)
			free(cub->texture->we);
		if (cub->texture->ea)
			free(cub->texture->ea);
		free(cub->texture->no_img);
		free(cub->texture->so_img);
		free(cub->texture->we_img);
		free(cub->texture->ea_img);
	}
	free(cub->texture);
	if (cub->map)
		free_strs(cub->map);
	if (cub->buff)
	{
		mlx_destroy_image(cub->mlx, cub->buff->img);
		free(cub->buff);
	}
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

void	print_data(t_cub *cub)
{
	int	i;

	ft_putstr_fd("NO: ", 1);
	(ft_putstr_fd(cub->texture->no, 1), ft_putstr_fd("\n", 1));
	ft_putstr_fd("SO: ", 1);
	(ft_putstr_fd(cub->texture->so, 1), ft_putstr_fd("\n", 1));
	ft_putstr_fd("WE: ", 1);
	(ft_putstr_fd(cub->texture->we, 1), ft_putstr_fd("\n", 1));
	ft_putstr_fd("EA: ", 1);
	(ft_putstr_fd(cub->texture->ea, 1), ft_putstr_fd("\n", 1));
	(ft_putstr_fd("F: ", 1), ft_putnbr_fd(cub->floor[0], 1));
	(ft_putstr_fd(",", 1), ft_putnbr_fd(cub->floor[1], 1));
	ft_putstr_fd(",", 1);
	(ft_putnbr_fd(cub->floor[2], 1), ft_putstr_fd("\n", 1));
	(ft_putstr_fd("C: ", 1), ft_putnbr_fd(cub->ceiling[0], 1));
	(ft_putstr_fd(",", 1), ft_putnbr_fd(cub->ceiling[1], 1));
	ft_putstr_fd(",", 1);
	(ft_putnbr_fd(cub->ceiling[2], 1), ft_putstr_fd("\n", 1));
	ft_putstr_fd("Map:\n", 1);
	i = 0;
	while (cub->map[i])
	{
		(ft_putstr_fd(cub->map[i], 1), ft_putstr_fd("\n", 1));
		i++;
	}
}
