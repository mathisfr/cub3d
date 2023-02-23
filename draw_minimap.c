/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:14:20 by lloison           #+#    #+#             */
/*   Updated: 2023/02/23 18:28:08 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_tile_type(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->map->max_x_size
		|| y >= data->map->max_y_size || data->map->map_arr[y][x] == ' ')
		return (-1);
	return (data->map->map_arr[y][x] - '0');
}

static void	draw_minimap_wall(t_data *data,
	int tile_pos_x, int tile_pos_y, int type)
{
	int	x;
	int	y;
	int	color;

	x = (tile_pos_x - (data->player->tile_pos.x - MINIMAP_NB_WALL)) *
		(data->image.map_img->width / (float)(MINIMAP_NB_WALL * 2));
	x -= (float)((int)data->player->map_pos.x % (int)WALL_SIZE) *
		data->image.map_img->width / (float)(MINIMAP_NB_WALL * 2) / WALL_SIZE;
	y = (tile_pos_y - (data->player->tile_pos.y - MINIMAP_NB_WALL)) *
		(data->image.map_img->height / (float)(MINIMAP_NB_WALL * 2));
	y -= (float)((int)data->player->map_pos.y % (int)WALL_SIZE) *
		data->image.map_img->height / (float)(MINIMAP_NB_WALL * 2) / WALL_SIZE;
	if (type == -1)
		color = 0xBB000000;
	else if (type == 0)
		color = 0x33000000;
	else if (type == 1)
		color = 0xFF00FF00;
	else if (type == 2)
		color = 0xFFFF0000;
	else
		color = 0x99FF0000;
	ft_minimap_rectangle(x, y,
		data->image.map_img->width / (float)(MINIMAP_NB_WALL * 2) + 1,
		data->image.map_img->height / (float)(MINIMAP_NB_WALL * 2) + 1,
		color, data->image.map_img);
}

void	draw_minimap(t_data *data)
{
	int	x;
	int	y;

	y = data->player->tile_pos.y - MINIMAP_NB_WALL;
	while (y < data->player->tile_pos.y + MINIMAP_NB_WALL + 1)
	{
		x = data->player->tile_pos.x - MINIMAP_NB_WALL;
		while (x < data->player->tile_pos.x + MINIMAP_NB_WALL + 1)
		{
			draw_minimap_wall(data, x, y, get_tile_type(data, x, y));
			x++;
		}
		y++;
	}
	ft_circle(MINIMAP_WIDTH2, MINIMAP_WIDTH2,
		5, 0xFF0000FF, data->image.map_img);
}
