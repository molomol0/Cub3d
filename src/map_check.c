/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:25:57 by ftholoza          #+#    #+#             */
/*   Updated: 2024/03/19 02:04:26 by francesco        ###   ########.fr       */
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
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (spwn);
}

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

int	flood_fill(char **map, int x, int y, int *signal)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	map[y][x] = '2';
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

static int	is_valid(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '0' || c == '1' || c == ' ')
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
	if (!n)
		return (0);
	if (check_char_map(map) == 0)
		return (free(n), err("Error: Invalid map\n"));
	flood_fill(map, n[1], n[0], &signal);
	if (signal == 1)
	{
		free(n);
		return (err("Error: Invalid map\n"));
	}
	printf("Valid map\n");
	free(n);
	return (1);
}


