/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:55:09 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/18 17:09:19 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_struct.h"
#include "cub.h"

int	check_data(t_cub *cub)
{
	if (cub->texture->no == NULL || cub->texture->so == NULL
		|| cub->texture->we == NULL || cub->texture->ea == NULL
		|| cub->floor[0] == -1 || cub->ceiling[0] == -1
		|| cub->map == NULL)
	{
		ft_putstr_fd("Error\nMissing data\n", 2);
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
	cub->texture = malloc(sizeof(t_texture));
	if (!cub->texture)
	{
		ft_putstr_fd("Error\nMalloc failed\n", 2);
		return (NULL);
	}
	cub->texture->no = NULL;
	cub->texture->so = NULL;
	cub->texture->we = NULL;
	cub->texture->ea = NULL;
	cub->floor[0] = -1;
	cub->ceiling[0] = -1;
	cub->map = NULL;
	if (travel_file(argv[1], cub) == -1 || check_data(cub) == -1)
	{
		free_data(cub);
		return (NULL);
	}
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
	}
	free(cub->texture);
	if (cub->map)
		free_strs(cub->map);
	free(cub);
}

void	print_data(t_cub *cub)
{
	ft_putstr_fd("NO: ", 1);
	(ft_putstr_fd(cub->texture->no, 1), ft_putstr_fd("\n", 1));
	ft_putstr_fd("SO: ", 1);
	(ft_putstr_fd(cub->texture->so, 1), ft_putstr_fd("\n", 1));
	ft_putstr_fd("WE: ", 1);
	(ft_putstr_fd(cub->texture->we, 1), ft_putstr_fd("\n", 1));
	ft_putstr_fd("EA: ", 1);
	(ft_putstr_fd(cub->texture->ea, 1), ft_putstr_fd("\n", 1));
	ft_putstr_fd("F: ", 1);
	ft_putnbr_fd(cub->floor[0], 1);
	ft_putstr_fd(",", 1);
	ft_putnbr_fd(cub->floor[1], 1);
	ft_putstr_fd(",", 1);
	(ft_putnbr_fd(cub->floor[2], 1), ft_putstr_fd("\n", 1));
	ft_putstr_fd("C: ", 1);
	ft_putnbr_fd(cub->ceiling[0], 1);
	ft_putstr_fd(",", 1);
	ft_putnbr_fd(cub->ceiling[1], 1);
	ft_putstr_fd(",", 1);
	(ft_putnbr_fd(cub->ceiling[2], 1), ft_putstr_fd("\n", 1));
	ft_putstr_fd("Map:\n", 1);
	int i = 0;
	while (cub->map[i])
	{
		ft_putstr_fd(cub->map[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}
