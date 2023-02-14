/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:14:01 by lloison           #+#    #+#             */
/*   Updated: 2023/02/13 17:47:49 by matfranc         ###   ########.fr       */
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

#endif
