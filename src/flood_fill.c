/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:21:30 by ftholoza          #+#    #+#             */
/*   Updated: 2024/04/02 14:14:16 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct.h"

int	check_if_null(char **map, int x, int y)
{
	int	line_count;
	int	len_line;

	line_count = 0;
	if (y < 0 || x < 0)
		return (1);
	while (map[line_count])
		line_count++;
	if (y >= line_count)
		return (1);
	len_line = ft_strlen(map[y]);
	if (x >= len_line)
		return (1);
	if (map[y][x] == ' ')
		return (1);
	return (0);
}

int	check_and_replace(char **map, int x, int y)
{
	if (map[y][x] != '1' && map[y][x] != '2')
	{
		map[y][x] = '2';
		return (1);
	}
	else
		return (0);
}

int	fill(char **map, int x, int y)
{
	int	i;

	i = 1;
	if (check_if_null(map, x + 1, y))
		return (0);
	else
		i += check_and_replace(map, x + 1, y);
	if (check_if_null(map, x - 1, y))
		return (0);
	else
		i += check_and_replace(map, x - 1, y);
	if (check_if_null(map, x, y - 1))
		return (0);
	else
		i += check_and_replace(map, x, y - 1);
	if (check_if_null(map, x, y + 1))
		return (0);
	else
		i += check_and_replace(map, x, y + 1);
	return (i);
}

int	replace_zero(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == '0' || map[j][i] == '3')
				map[j][i] = '2';
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	flood_fill(char **map, int x, int y, int *signal)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	replace_zero(map);
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == '2')
			{
				check = fill(map, i, j);
				if (check == 0)
					*signal = 1;
				if (check > 1)
					flood_fill(map, x, y, signal);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}
