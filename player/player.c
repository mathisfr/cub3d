/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:56:10 by lloison           #+#    #+#             */
/*   Updated: 2023/02/23 18:27:06 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	is_player(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (TRUE);
	return (FALSE);
}

static void	set_player_angle(t_player *player, char p)
{
	if (p == 'N')
		player->angle = 0;
	else if (p == 'E')
		player->angle = 90;
	else if (p == 'S')
		player->angle = 180;
	else if (p == 'W')
		player->angle = 270;
}

//Initialize player position in the player struct
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
				player->map_pos = tile_pos_to_map_pos(player->tile_pos);
				set_player_angle(player, map->map_arr[y][x]);
				map->map_arr[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

//Init the player struct to the starting value
t_player	*init_player(t_map *map)
{
	t_player	*player;

	player = ft_calloc(sizeof(t_player), 1);
	if (!player)
		malloc_error();
	set_player_pos(player, map);
	update_player_collider(player, map, TRUE);
	return (player);
}

//Update player pos based on the instance (can be removed later)
//Update player collision as well
void	update_player(t_player *player, t_map *map)
{
	while (player->angle < 0)
		player->angle += 360;
	while (player->angle >= 360)
		player->angle -= 360;

	if (player->movement.x != 0 || player->movement.y != 0)
	{
		update_player_collider(player, map, FALSE);
		handle_player_collision(player);
	}
}
