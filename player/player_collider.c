/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collider.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:43:54 by lloison           #+#    #+#             */
/*   Updated: 2023/02/23 15:34:07 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	check_tile_pos2(t_player *player, t_tile_pos tile_pos)
{
	if (tile_pos == BL && map_pos_to_tile_pos(v_pos(player->map_pos.x,
				player->map_pos.y + PL_HITBOX2)).y != player->tile_pos.y
		&& map_pos_to_tile_pos(v_pos(player->map_pos.x - PL_HITBOX2,
				player->map_pos.y)).x != player->tile_pos.x)
		return (TRUE);
	if (tile_pos == L && map_pos_to_tile_pos(v_pos(player->map_pos.x - PL_HITBOX2,
				player->map_pos.y)).x != player->tile_pos.x)
		return (TRUE);
	return (FALSE);
}

//check the desired tile_pos which is one of the 8 adjacent tile to see if the player is inside that tile
static t_bool	check_tile_pos(t_player *player, t_tile_pos t_p)
{
	if (t_p == TL && map_pos_to_tile_pos(v_pos(player->map_pos.x - PL_HITBOX2,
				player->map_pos.y)).x != player->tile_pos.x
		&& map_pos_to_tile_pos(v_pos(player->map_pos.x,
				player->map_pos.y - PL_HITBOX2)).y != player->tile_pos.y)
		return (TRUE);
	if (t_p == T && map_pos_to_tile_pos(v_pos(player->map_pos.x,
				player->map_pos.y - PL_HITBOX2)).y != player->tile_pos.y)
		return (TRUE);
	if (t_p == TR && map_pos_to_tile_pos(v_pos(player->map_pos.x,
				player->map_pos.y - PL_HITBOX2)).y != player->tile_pos.y
		&& map_pos_to_tile_pos(v_pos(player->map_pos.x + PL_HITBOX2,
				player->map_pos.y)).x != player->tile_pos.x)
		return (TRUE);
	if (t_p == R && map_pos_to_tile_pos(v_pos(player->map_pos.x + PL_HITBOX2,
				player->map_pos.y)).x != player->tile_pos.x)
		return (TRUE);
	if (t_p == BR && map_pos_to_tile_pos(v_pos(player->map_pos.x + PL_HITBOX2,
				player->map_pos.y)).x != player->tile_pos.x
		&& map_pos_to_tile_pos(v_pos(player->map_pos.x,
				player->map_pos.y + PL_HITBOX2)).y != player->tile_pos.y)
		return (TRUE);
	if (t_p == B && map_pos_to_tile_pos(v_pos(player->map_pos.x,
				player->map_pos.y + PL_HITBOX2)).y != player->tile_pos.y)
		return (TRUE);
	return (check_tile_pos2(player, t_p));
}

//add a tile pos to the list
static void	add_tile_to_list(t_player *player,
	t_list **output, t_tile_pos tile_pos)
{
	t_list	*t;

	t = NULL;
	if (tile_pos == TL)
		t = ft_lstnew(ptr_pos(player->tile_pos.x - 1, player->tile_pos.y - 1));
	else if (tile_pos == T)
		t = ft_lstnew(ptr_pos(player->tile_pos.x, player->tile_pos.y - 1));
	else if (tile_pos == TR)
		t = ft_lstnew(ptr_pos(player->tile_pos.x + 1, player->tile_pos.y - 1));
	else if (tile_pos == R)
		t = ft_lstnew(ptr_pos(player->tile_pos.x + 1, player->tile_pos.y));
	else if (tile_pos == BR)
		t = ft_lstnew(ptr_pos(player->tile_pos.x + 1, player->tile_pos.y + 1));
	else if (tile_pos == B)
		t = ft_lstnew(ptr_pos(player->tile_pos.x, player->tile_pos.y + 1));
	else if (tile_pos == BL)
		t = ft_lstnew(ptr_pos(player->tile_pos.x - 1, player->tile_pos.y + 1));
	else if (tile_pos == L)
		t = ft_lstnew(ptr_pos(player->tile_pos.x - 1, player->tile_pos.y));
	if (!t)
		malloc_error();
	ft_lstadd_back(output, t);
}

//Set the max and min value if adjacent tester tile is a wall (only set if it's unset)
void	set_max_and_min(t_pos *max, t_pos *min,
	t_map *map, t_pos tile_pos)
{
	if (min->y == 0
		&& (has_collider(map->map_arr[(int)tile_pos.y - 1][(int)tile_pos.x])))
		min->y = tile_pos_to_map_pos(pos(tile_pos.x,
					tile_pos.y - 1)).y + WALL_SIZE / 2 + PL_HITBOX;
	if (max->y == 0
		&& (has_collider(map->map_arr[(int)tile_pos.y + 1][(int)tile_pos.x])))
		max->y = tile_pos_to_map_pos(pos(tile_pos.x,
					tile_pos.y + 1)).y - WALL_SIZE / 2 - PL_HITBOX;
	if (min->x == 0
		&& (has_collider(map->map_arr[(int)tile_pos.y][(int)tile_pos.x - 1])))
		min->x = tile_pos_to_map_pos(pos(tile_pos.x - 1, tile_pos.y)).x
			+ WALL_SIZE / 2 + PL_HITBOX;
	if (max->x == 0
		&& (has_collider(map->map_arr[(int)tile_pos.y][(int)tile_pos.x + 1])))
		max->x = tile_pos_to_map_pos(pos(tile_pos.x + 1, tile_pos.y)).x
			- WALL_SIZE / 2 - PL_HITBOX;
}

//Get all tiles the player is currently in
t_list	*get_all_tiles(t_player *player)
{
	t_list	*output;

	output = ft_lstnew(ptr_pos(player->tile_pos.x, player->tile_pos.y));
	if (!output)
		malloc_error();
	if (check_tile_pos(player, TL))
		add_tile_to_list(player, &output, TL);
	if (check_tile_pos(player, T))
		add_tile_to_list(player, &output, T);
	if (check_tile_pos(player, TR))
		add_tile_to_list(player, &output, TR);
	if (check_tile_pos(player, R))
		add_tile_to_list(player, &output, R);
	if (check_tile_pos(player, BR))
		add_tile_to_list(player, &output, BR);
	if (check_tile_pos(player, B))
		add_tile_to_list(player, &output, B);
	if (check_tile_pos(player, BL))
		add_tile_to_list(player, &output, BL);
	if (check_tile_pos(player, L))
		add_tile_to_list(player, &output, L);
	return (output);
}
