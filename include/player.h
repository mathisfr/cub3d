/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:13:14 by lloison           #+#    #+#             */
/*   Updated: 2023/02/22 15:36:33 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "vector.h"
# include "map.h"

typedef enum e_tile_pos {TL, T, TR, R, BR, B, BL, L}	t_tile_pos;

typedef struct s_player_collider
{
	t_pos	max;
	t_pos	min;
	t_list	*all_tiles;
}	t_player_collider;

typedef struct s_player
{
	t_pos				tile_pos;
	t_vector			map_pos;
	int					angle;
	t_player_collider	collider;
	t_vector			dir;
	t_vector			movement;
}	t_player;

t_player	*init_player(t_map *map);
void		update_player_collider(t_player *player, t_map *map,
				t_bool force_update);
void		handle_player_collision(t_player *player);
void		set_max_and_min(t_pos *max, t_pos *min,
				t_map *map, t_pos tile_pos);
t_list		*get_all_tiles(t_player *player);
void		update_player(t_player *player, t_pos instance_pos, t_map *map);

#endif
