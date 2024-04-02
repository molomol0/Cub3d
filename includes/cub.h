/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:18:25 by ftholoza          #+#    #+#             */
/*   Updated: 2024/04/02 19:43:44 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "cub_struct.h"
# include "libft.h"
# include <X11/X.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

# define W_WIDTH 450
# define W_HEIGHT 450
# define TILE_SIZE 50
# define PLAYER_SPEED 1

# define EVENT_CLOSE_BTN 17
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_E 101
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_SPACE 32
# define KEY_ALT 65513
# define KEY_SHIFT 65505
# define FOV 90
# define M_PI 3.14159265358979323846

int			check_data(t_cub *cub);
void		null_init(t_cub *cub);
int			malloc_texture(t_cub *cub);
int			malloc_pistol(t_cub *cub);
int			init_buff_minimap(t_cub *cub);

int			travel_file(char *file, t_cub *cub);
t_cub		*init_data(char **argv);
void		free_data(t_cub *cub);
void		free_texture(t_cub *cub);
void		print_data(t_cub *cub);
t_player	*player_struct_init(char **map);

void		valid_color(int *color, t_cub *cub, char *line);
void		print_duplicate(char *duplicated, char *type, t_cub *cub,
				char *line);
int			skip_space(char *line, char *texture);
int			print_err(char *str);

char		*ft_strappen(char *s1, char const *s2);
int			other_char(char *line);
int			only_wall(char *line);
void		put_map(char *line, t_cub *cub);
void		get_texture(t_cub *cub);
int			check_line_ok(char *line);
void		get_gun_img(t_cub *cub);
void		exit_map(t_cub *cub, char *line, char *str);
void		delete_point_texture(char **direction);
void		get_comas(char *line, int *first_coma, int *second_coma);

int			texture_valid(char *texture);

int			map_check(char **map);
int			flood_fill(char **map, int x, int y, int *signal);
int			check_if_null(char **map, int x, int y);
void		find_spawn(char **map, int *x, int *y);
char		**clone_tab(char **tab);

void		init_window(t_cub *cub);
int			clean_close(t_cub *cub);

void		get_ray_dir(t_player *player);
void		get_delta(t_player *player);
void		get_side(t_player *player);
void		rotate_player(t_player *player, int degrees);
void		ray_casting(t_cub *cub, t_player *player);

void		render_wall(t_cub *cub, t_ray *ray);
void		animation(t_cub *cub);
void		put_first_frame(t_cub *cub);
void		put_middle_frame(t_cub *cub, t_img *img);
void		put_last_frame(t_cub *cub);

void		my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
void		my_put_img_to_buff(t_img *img, int x, int y, t_cub *cub);
void		put_pixel(t_img *img, int x, int y, int color);
int			draw_minimap(t_cub *cub);
int			convert_color(int *color);
int			get_xpm_color(t_img *img, int y, t_cub *cub, int t_pix);
int			get_color(t_cub *cub, int flag, int y, int t_pix);
int			mouse_track(int x, int y, t_cub *cub);
int			create_trgb(int t, int r, int g, int b);
long		ft_gettime(long start);
long		ft_get_start(void);
int			game_run(t_cub *cub);
int			mouse_event(int code, int x, int y, t_cub *cub);

int			check_press(int key, t_cub *cub);
int			check_release(int key, t_cub *cub);
int			check_backward(t_cub *cub);
int			check_forward(t_cub *cub);
int			rotate_right(t_cub *cub, int rotate);
int			rotate_left(t_cub *cub, int rotate);
void		do_move(t_cub *cub);
void		check_doors(t_cub *cub);
void		fire_ray(t_player *player, t_cub *cub);
void		get_perpwall_dist(t_player *player);
void		init_ray_struct(t_player *player);
void		fire_ray_two(t_player *player, t_cub *cub);
void		fire_ray_one(t_player *player, t_cub *cub);

#endif