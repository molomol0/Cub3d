/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:55:09 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/22 16:38:11 by jdenis           ###   ########.fr       */
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
	cub->map = NULL;
	cub->mlx = NULL;
	cub->win = NULL;
	cub->buff = NULL;
}

t_cub	*init_data(char **argv)
{
	t_cub	*cub;
	int		bit_per_pixel;
	int		line_length;
	int		endian;

	cub = malloc(sizeof(t_cub));
	if (!cub)
	{
		ft_putstr_fd("Error\nMalloc failed\n", 2);
		return (NULL);
	}
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
	cub->buff = malloc(sizeof(t_img));
	init_window(cub);
	cub->buff->img = mlx_new_image(cub->mlx, W_WIDTH, W_HEIGHT);
	cub->buff->addr = mlx_get_data_addr(cub->buff->img, &bit_per_pixel,
			&line_length, &endian);
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
