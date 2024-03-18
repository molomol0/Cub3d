/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:42:07 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/18 15:19:00 by jdenis           ###   ########.fr       */
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
}				t_cub;	

#endif