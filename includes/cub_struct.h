/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:42:07 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/21 23:35:39 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCT_H
# define CUB_STRUCT_H

typedef struct s_texture
{
	char	*no;
	void	*no_img;
	char	*so;
	void	*so_img;
	char	*we;
	void	*we_img;
	char	*ea;
	void	*ea_img;
}			t_texture;

typedef struct s_ray
{
	double	raypoint_x;
	double	raypoint_y;
	double	raydir_x;
	double	raydir_y;
	double	delta_x;
	double	delta_y;
	int		step_x;
	int		step_y;
	double	side_x;
	double	side_y;
	double	x;
	double	scale;
	int		hit;
	int		map_x;
	int		map_y;
	int		side;
	double	distance;
	double	wall_x;
	double	wall_y;
}				t_ray;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	pix_px;
	double	pix_py;
	char	orientation;
	double	dir_x;
	double	dir_y;
	double	camera_plane_left_x;
	double	camera_plane_left_y;
	double	camera_plane_right_x;
	double	camera_plane_right_y;
	double	camera_plane_lenght;
	t_ray	*ray;
}	t_player;

typedef struct s_cub
{
	t_texture	*texture;
	int			floor[3];
	int			ceiling[3];
	char		**map;
	int			tmp;
	void		*mlx;
	void		*win;
}				t_cub;

#endif