/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:14:01 by lloison           #+#    #+#             */
/*   Updated: 2023/02/22 16:47:47 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "MLX42/MLX42.h"

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

typedef enum e_side {LEFT, RIGHT, TOP, BOTTOM}	t_side;

typedef struct	s_raycastHit
{
	t_vector		pos;
	float			perpWallDist;
	t_side			side;
}	t_raycastHit;

typedef struct s_pos
{
	int		x;
	int		y;
}	t_pos;

t_vector	tile_pos_to_map_pos(t_pos tile_pos);
t_pos		map_pos_to_tile_pos(t_vector map_pos);
t_pos	pos(float x, float y);
t_vector v_pos(float x, float y);
t_pos	*ptr_pos(float x, float y);
t_vector	normalize_vector(t_vector v);
void	ft_vector_rotation(t_vector *vec, float angle);
float InvSqrt(float x);

#endif
