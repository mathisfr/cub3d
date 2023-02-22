/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:14:01 by lloison           #+#    #+#             */
/*   Updated: 2023/02/16 18:50:50 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

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

t_pos	tile_pos_to_map_pos(t_pos tile_pos);
t_pos	map_pos_to_tile_pos(t_pos map_pos);
t_pos	pos(float x, float y);
t_pos	*ptr_pos(float x, float y);
t_vector	normalize_vector(t_vector v);
void	ft_vector_rotation(t_vector *vec, float angle);
float InvSqrt(float x);

#endif
