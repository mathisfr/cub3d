/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:35:14 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/24 09:49:35 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H
# include "vector.h"

typedef struct s_dda
{
	t_vector	dir;
	t_vector	*side_dist;
	t_vector	delta_dist;
	t_pos		tile_pos;
}		t_dda;

int	execute_dda(t_data *data, t_dda *dda);

#endif
