/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:18:25 by ftholoza          #+#    #+#             */
/*   Updated: 2024/03/18 15:25:04 by jdenis           ###   ########.fr       */
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
void	put_map(char *line, t_cub *cub, int fd);

#endif