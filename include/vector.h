/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:14:01 by lloison           #+#    #+#             */
/*   Updated: 2023/02/22 14:07:55 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include "MLX42/MLX42.h"

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

typedef struct s_vector
{
	float	x;
	float	y;
	float	length;
}	t_vector;

typedef struct	s_raycastHit
{
	t_vector		pos;
	float			perpWallDist;
	mlx_texture_t	*texture;
}	t_raycastHit;

t_pos	tile_pos_to_map_pos(t_pos tile_pos);
t_pos	map_pos_to_tile_pos(t_pos map_pos);
t_pos	pos(float x, float y);
t_pos	*ptr_pos(float x, float y);
t_vector	normalize_vector(t_vector v);
void	ft_vector_rotation(t_vector *vec, float angle);
float InvSqrt(float x);

#endif
