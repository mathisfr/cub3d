/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:56:10 by lloison           #+#    #+#             */
/*   Updated: 2023/02/15 14:11:12 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	is_player(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (TRUE);
	return (FALSE);
}

static void	set_player_pos(t_player *player, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->max_y_size)
	{
		x = 0;
		while (x < map->max_x_size)
		{
			if (is_player(map->map_arr[y][x]))
			{
				player->tile_pos.y = y;
				player->tile_pos.x = x;
				map->map_arr[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

t_player	*init_player(t_map *map)
{
	t_player	*player;

	player = ft_calloc(sizeof(t_player), 1);
	if (!player)
		malloc_error();
	set_player_pos(player, map);
	if (map->map_arr[(int)player->tile_pos.y][(int)player->tile_pos.x] == 'N')
		player->angle = 0;
	else if (map->map_arr[(int)player->tile_pos.y]
		[(int)player->tile_pos.x] == 'E')
		player->angle = 90;
	else if (map->map_arr[(int)player->tile_pos.y]
		[(int)player->tile_pos.x] == 'S')
		player->angle = 180;
	else if (map->map_arr[(int)player->tile_pos.y]
		[(int)player->tile_pos.x] == 'W')
		player->angle = 270;
	update_player_collider(player, map, TRUE);
	return (player);
}

void	update_player(t_player *player, t_pos instance_pos, t_map *map)
{
	player->map_pos.x = instance_pos.x + PL_HITBOX;
	player->map_pos.y = instance_pos.y + PL_HITBOX;
	player->tile_pos = map_pos_to_tile_pos(player->map_pos);
	printf("player map pos : %fx%fy\n", player->map_pos.x, player->map_pos.y);
	update_player_collider(player, map, FALSE);
	handle_player_collision(player);
	//player->movement = normalize_vector(player->movement);
}
