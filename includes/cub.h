/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:18:25 by ftholoza          #+#    #+#             */
/*   Updated: 2024/03/18 23:36:35 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB_H
# define CUB_H

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#include "cub_struct.h"
#include "libft.h"

int		travel_file(char *file, t_cub *cub);
t_cub	*init_data(char **argv);
void	free_data(t_cub *cub);
void	print_data(t_cub *cub);


void	valid_color(int *color, t_cub *cub, char *line);
void	print_duplicate(char *duplicated, char *type, t_cub *cub, char *line,
		int fd);
int		skip_space(char *line, char *texture);
int		print_err(char *str);

char	*ft_strappen(char *s1, char const *s2);
int		other_char(char *line);
int		only_wall(char *line);
void	put_map(char *line, t_cub *cub, int fd);

int	map_check(char **map);

#endif