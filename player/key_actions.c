/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:00:38 by lloison           #+#    #+#             */
/*   Updated: 2023/02/25 14:31:31 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	look_mouse(double xpos, double ypos, void *param)
{
	t_data	*data;

	(void) ypos;
	data = (t_data *)param;
	if (xpos > 0 && xpos < WINDOW_WIDTH && xpos != WINDOW_WIDTH / 2)
	{
		if (xpos > WINDOW_WIDTH / 2)
			data->player->angle += ((xpos - (WINDOW_WIDTH / 2))
					* SENSITIVITY * data->delta_time * 20.0);
		else if (xpos < WINDOW_WIDTH / 2)
			data->player->angle -= (((WINDOW_WIDTH / 2) - xpos)
					* SENSITIVITY * data->delta_time * 20.0);
		mlx_set_mouse_pos(data->mlx, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	}
}

static char	*get_front_tile(t_data *data, t_pos	*tpos)
{
	t_pos	pl_pos;

	pl_pos = data->player->tile_pos;
	if (data->player->angle > 315 || data->player->angle <= 45)
	{
		*tpos = pos(pl_pos.x, pl_pos.y - 1);
		return (&data->map->map_arr[pl_pos.y - 1][pl_pos.x]);
	}
	if (data->player->angle > 45 && data->player->angle <= 135)
	{
		*tpos = pos(pl_pos.x + 1, pl_pos.y);
		return (&data->map->map_arr[pl_pos.y][pl_pos.x + 1]);
	}
	if (data->player->angle > 135 && data->player->angle <= 225)
	{
		*tpos = pos(pl_pos.x, pl_pos.y + 1);
		return (&data->map->map_arr[pl_pos.y + 1][pl_pos.x]);
	}
	*tpos = pos(pl_pos.x - 1, pl_pos.y);
	return (&data->map->map_arr[pl_pos.y][pl_pos.x - 1]);
}

void	doors_manager(char door, char state, t_data *data)
{
	char	*front_tile;
	t_pos	tile_pos;

	front_tile = get_front_tile(data, &tile_pos);
	if (*front_tile == door && !is_in_collider(data, tile_pos))
		*front_tile = state;
	else if (*front_tile == state && !is_in_collider(data, tile_pos))
		*front_tile = door;
}

void	key_action(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.action == MLX_PRESS
		&& (keydata.key == MLX_KEY_SPACE))
		doors_manager('2', '3', data);
	else if (keydata.action == MLX_PRESS
		&& keydata.key == MLX_KEY_LEFT_SHIFT)
		data->key_action = TRUE;
	else if (keydata.action == MLX_RELEASE
		&& keydata.key == MLX_KEY_LEFT_SHIFT)
		data->key_action = FALSE;
}

void	mouse_action(mouse_key_t button, action_t action,
	modifier_key_t mods, void *param)
{
	t_data	*data;

	(void) mods;
	data = (t_data *)param;
	if (button == MLX_MOUSE_BUTTON_LEFT
		&& action == MLX_PRESS)
		data->key_action = TRUE;
	else if (button == MLX_MOUSE_BUTTON_LEFT
		&& action == MLX_RELEASE)
		data->key_action = FALSE;
}
