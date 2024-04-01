/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:25:57 by ftholoza          #+#    #+#             */
/*   Updated: 2024/04/01 12:06:35 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"

void	find_spawn(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'W' || map[j][i] == 'E'
				|| map[j][i] == 'S')
			{
				*y = j;
				*x = i;
				return ;
			}
			i++;
		}
		i = 0;
		j++;
	}
	*x = -1;
	return ;
}

static int	is_valid(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == '0' || c == '1' || c == '3' || c == ' ')
		return (1);
	else
		return (0);
}

int	check_char_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (!is_valid(map[j][i]))
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	err(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (0);
}

int	map_check(char **m_map)
{
	int		signal;
	int		spwnx;
	int		spwny;
	char	**map;

	signal = 0;
	find_spawn(m_map, &spwnx, &spwny);
	if (spwnx == -1)
		return (err("Error: Invalid map\n"));
	if (check_char_map(m_map) == 0)
		return (err("Error: Invalid map\n"));
	map = clone_tab(m_map);
	flood_fill(map, spwnx, spwny, &signal);
	if (signal == 1)
	{
		free_strs(map);
		return (err("Error: Invalid map\n"));
	}
	free_strs(map);
	return (1);
}
