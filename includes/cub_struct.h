/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:42:07 by jdenis            #+#    #+#             */
/*   Updated: 2024/04/02 18:19:24 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCT_H
# define CUB_STRUCT_H

# include <stdbool.h>

enum	e_side
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	DOOR_NS,
	DOOR_EW
};

typedef struct s_minimap
{
	double	x;
	double	y;
	double	x_max;
	double	y_max;
	double	scale_x;
	double	scale_y;
	double	x_pos;
	double	y_pos;
}	t_minimap;

typedef struct s_ray
{
	double		raypoint_x;
	double		raypoint_y;
	double		raydir_x;
	double		raydir_y;
	double		delta_x;
	double		delta_y;
	int			step_x;
	int			step_y;
	double		side_x;
	double		side_y;
	double		x;
	double		scale;
	int			hit;
	int			map_x;
	int			map_y;
	enum e_side	side;
	double		eu_dist;
	double		perp_dist;
	int			wall_h;
	int			wall_w;
	int			wall_x;
	char		hit_type;
	int			hit_x;
	int			hit_y;
}				t_ray;

typedef struct s_player
{
	double		map_x;
	double		map_y;
	double		pos_x;
	double		pos_y;
	char		orientation;
	double		dir_x;
	double		dir_y;
	double		camera_plane_left_x;
	double		camera_plane_left_y;
	double		camera_plane_right_x;
	double		camera_plane_right_y;
	double		camera_plane_lenght;
	t_ray		*ray;
	bool		move[5];
	int			speed;
}				t_player;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bit_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_texture
{
	char		*no;
	t_img		*no_img;
	char		*so;
	t_img		*so_img;
	char		*we;
	t_img		*we_img;
	char		*ea;
	t_img		*ea_img;
	t_img		*pistol;
	char		*pi;
	t_img		*pistol_flame;
	char		*pif;
	t_img		*pistol_r1;
	char		*pir1;
	t_img		*pistol_r2;
	char		*pir2;
	t_img		*door_img;
	char		*door;
}				t_texture;

typedef struct s_cub
{
	t_texture	*texture;
	int			floor[3];
	int			ceiling[3];
	char		**map;
	int			tmp;
	void		*mlx;
	void		*win;
	t_img		*buff;
	t_img		*minimap;
	t_player	*player;
	t_minimap	*minimap_t;
	int			prev_mouse_x;
	int			end;
	long		start_time;
	long		anim_start;
	long		anim_time;
	long		frame_start;
	int			on_of;
	long		current_time;
	long		old_time;
	char		*dst;
	double		scale_y;
	double		scale_x;
	int			real_x;
	int			real_y;
	double		wall_x;
}				t_cub;

#endif