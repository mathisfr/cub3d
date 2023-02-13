/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:13:14 by lloison           #+#    #+#             */
/*   Updated: 2023/02/13 16:16:20 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "vector.h"
# include "map.h"

typedef struct s_player
{
	t_pos	tile_pos;
	int		angle;
}	t_player;

t_player	*init_player(t_map *map);

#endif