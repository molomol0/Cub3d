/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:42:07 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/19 19:26:26 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCT_H
# define CUB_STRUCT_H

typedef struct	s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}			t_texture;

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

#endif