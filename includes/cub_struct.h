/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:42:07 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/20 23:02:14 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCT_H
# define CUB_STRUCT_H

typedef struct	s_texture
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

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	char	orientation;
	double	dir_x;
	double	dir_y;
	double	camera_plane_left_x;
	double	camera_plane_left_y;
	double	camera_plane_right_x;
	double	camera_plane_right_y;
}	t_player;

typedef struct	s_cub
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