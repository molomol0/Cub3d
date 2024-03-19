/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:25:57 by ftholoza          #+#    #+#             */
/*   Updated: 2024/03/19 14:26:44 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"

int	*find_spawn(char **map)
{
	int	*spwn;
	int	i;
	int	j;

	i = 0;
	j = 0;
	spwn = malloc(sizeof(int) * 2);
	if (!spwn)
		return (NULL);
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'N')
			{
				spwn[0] = j;
				spwn[1] = i;
				return (spwn);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (free(spwn), NULL);
}

static int	is_valid(char c)
{
	if (c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == '0' || c == '1' || c == ' ')
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

int	map_check(char **map)
{
	int	*n;
	int	signal;

	signal = 0;
	n = find_spawn(map);
	if (n == NULL)
		return (err("Error\n"));
	if (check_char_map(map) == 0)
		return (free(n), err("Error: Invalid map\n"));
	flood_fill(map, n[1], n[0], &signal);
	free(n);
	if (signal == 1)
		return (err("Error: Invalid map\n"));
	printf("Valid map\n");
	return (1);
}
