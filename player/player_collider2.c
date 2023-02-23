/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collider2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:37:59 by lloison           #+#    #+#             */
/*   Updated: 2023/02/23 18:26:57 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Update player collider
void	update_player_collider(t_player *player, t_map *map,
	t_bool force_update)
{
	t_list	*tile_list;

	(void) force_update;
	ft_lstclear(&(player->collider.all_tiles), free);
	player->collider.all_tiles = get_all_tiles(player);
	player->collider.max.x = 0;
	player->collider.max.y = 0;
	player->collider.min.x = 0;
	player->collider.min.y = 0;
	tile_list = player->collider.all_tiles;
	while (tile_list)
	{
		set_max_and_min(&player->collider.max,
			&player->collider.min,
			map, *((t_pos *)tile_list->content));
		tile_list = tile_list->next;
	}
	if (player->collider.max.x == 0)
		player->collider.max.x = 999999;
	if (player->collider.max.y == 0)
		player->collider.max.y = 999999;
}

//check for vertical collision
static t_bool	has_vertical_collision(t_player *player)
{
	float	final_pos_y;

	final_pos_y = player->map_pos.y + player->movement.y;
	if (final_pos_y > player->collider.max.y
		|| final_pos_y < player->collider.min.y)
	{
		if (player->movement.y < 0
			&& player->map_pos.y != player->collider.min.y)
		{
			player->movement.y = player->collider.min.y - player->map_pos.y;
			return (FALSE);
		}
		if (player->movement.y > 0
			&& player->map_pos.y != player->collider.max.y)
		{
			player->movement.y = player->collider.max.y - player->map_pos.y;
			return (FALSE);
		}
		return (TRUE);
	}
	return (FALSE);
}

//check for horizontal collision
static t_bool	has_horizontal_collision(t_player *player)
{
	float	final_pos_x;

	final_pos_x = player->map_pos.x + player->movement.x;
	if (final_pos_x > player->collider.max.x
		|| final_pos_x < player->collider.min.x)
	{
		if (player->movement.x < 0
			&& player->map_pos.x != player->collider.min.x)
		{
			player->movement.x = player->collider.min.x - player->map_pos.x;
			return (FALSE);
		}
		if (player->movement.x > 0
			&& player->map_pos.x != player->collider.max.x)
		{
			player->movement.x = player->collider.max.x - player->map_pos.x;
			return (FALSE);
		}
		return (TRUE);
	}
	return (FALSE);
}

void	handle_player_collision(t_player *player)
{
	if (player->movement.y != 0)
	{
		if (has_vertical_collision(player))
			player->movement.y = 0;
	}
	if (player->movement.x != 0)
	{
		if (has_horizontal_collision(player))
			player->movement.x = 0;
	}
}

t_bool	has_collider(char type)
{
	if (type == '1' || type == '2')
		return (TRUE);
	return (FALSE);
}
