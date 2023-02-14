/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collider2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:37:59 by lloison           #+#    #+#             */
/*   Updated: 2023/02/14 16:49:01 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_player_collider(t_player *player, t_map *map,
	t_bool force_update)
{
	t_list	*tile_list;

	if (!force_update && player->movement.x == 0 && player->movement.y == 0)
		return ;
	player->collider.all_tiles = get_all_tiles(player);
	//opti : check if all_tiles and output of all_tiles differ
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
		player->collider.max.x = 9999;
	if (player->collider.max.y == 0)
		player->collider.max.y = 9999;
}

static t_bool	has_vertical_collision(t_player *player)
{
	float	final_pos_y;

	final_pos_y = player->map_pos.y + player->movement.y * PLAYER_SPEED;
	if (final_pos_y > player->collider.max.y
		|| final_pos_y < player->collider.min.y)
		return (TRUE);
	return (FALSE);
}

static t_bool	has_horizontal_collision(t_player *player)
{
	float	final_pos_x;

	final_pos_x = player->map_pos.x + player->movement.x * PLAYER_SPEED;
	if (final_pos_x > player->collider.max.x
		|| final_pos_x < player->collider.min.x)
		return (TRUE);
	return (FALSE);
}

void	handle_player_collision(t_player *player)
{
	//printf("max.x : %f max.y : %f\nmin.x : %f min.y : %f\n", player->collider.max.x, player->collider.max.y, player->collider.min.x, player->collider.min.y);
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
