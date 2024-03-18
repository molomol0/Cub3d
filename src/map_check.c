/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:25:57 by ftholoza          #+#    #+#             */
/*   Updated: 2024/03/18 21:41:56 by ftholoza         ###   ########.fr       */
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

int	flood_fill(char **map, int x, int y)
{
	int	i;
	int	j;
	int	check;
	int	res;

	i = 0;
	j = 0;
	map[y][x] = '2';
	res = 1;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == '2')
			{
				check = fill(map, i, j);
				if (check == 0)
					return (0);
				if (check > 1)
					flood_fill(map, i, j);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	check_char(char c)
{
	
}

int	check_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][x])
		{
			
		}
	}
}

int	map_check(char **map)
{
	int	*n;
	int	x;

	n = find_spawn(map);
	if (!n)
		return (0);
	
	x = flood_fill(map, n[1], n[0]);
	if (x == 0)
		printf("Error: Invalid map\n");
	else
		printf("Valid map\n");
	free(n);
	return (x);
}


