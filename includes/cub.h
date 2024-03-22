/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:18:25 by ftholoza          #+#    #+#             */
/*   Updated: 2024/03/21 22:39:19 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "cub_struct.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define W_WIDTH 640
# define W_HEIGHT 480
# define TILE_SIZE 100
# define EVENT_CLOSE_BTN 17
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_SPACE 32
# define FOV 90
# define M_PI 3.14159265358979323846

int			travel_file(char *file, t_cub *cub);
t_cub		*init_data(char **argv);
void		free_data(t_cub *cub);
void		print_data(t_cub *cub);
t_player	*player_struct_init(char **map);

void		valid_color(int *color, t_cub *cub, char *line);
void		print_duplicate(char *duplicated, char *type, t_cub *cub, char *line);
int			skip_space(char *line, char *texture);
int			print_err(char *str);

char		*ft_strappen(char *s1, char const *s2);
int			other_char(char *line);
int			only_wall(char *line);
void		put_map(char *line, t_cub *cub);
void		get_texture(t_cub *cub);
int			texture_valid(char *texture);

int			map_check(char **map);
int			flood_fill(char **map, int x, int y, int *signal);
void		find_spawn(char **map, int *x, int *y);
char		**clone_tab(char **tab);

void		init_window(t_cub *cub);
int			clean_close(t_cub *cub);
int			key_event(int keycode, t_cub *cub);


void        rotate_player(t_player *player, int degrees);
void		ray_casting(t_cub *cub, t_player *player);

#endif