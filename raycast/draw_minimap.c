/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:14:20 by lloison           #+#    #+#             */
/*   Updated: 2023/02/24 09:15:46 by matfranc         ###   ########.fr       */
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

static int	select_color(int type)
{
	int	color;

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
	return (color);
}

static void	draw_minimap_wall(t_data *data, int tile_pos_x,
		int tile_pos_y, int type)
{
	t_vector	vec;
	t_vector	dest;
	int			color;

	vec.x = (tile_pos_x - (data->player->tile_pos.x - MINIMAP_NB_WALL))
		* (data->image.map_img->width / (float)(MINIMAP_NB_WALL * 2));
	vec.x -= (float)(((int)data->player->map_pos.x
				% (int)WALL_SIZE) * (float)(data->image.map_img->width
				/ (float)(MINIMAP_NB_WALL * 2) / WALL_SIZE));
	vec.y = (tile_pos_y - (data->player->tile_pos.y - MINIMAP_NB_WALL))
		* (data->image.map_img->height / (float)(MINIMAP_NB_WALL * 2));
	vec.y -= (float)(((int)data->player->map_pos.y
				% (int)WALL_SIZE) * (float)(data->image.map_img->height
				/ (float)(MINIMAP_NB_WALL * 2) / WALL_SIZE));
	color = select_color(type);
	dest.x = data->image.map_img->width / (float)(MINIMAP_NB_WALL * 2) + 1;
	dest.y = data->image.map_img->height / (float)(MINIMAP_NB_WALL * 2) + 1;
	ft_minimap_rectangle(vec, dest, color, data->image.map_img);
}

void	draw_minimap(t_data *data)
{
	t_vector	vec;
	t_vector	minimap_width2;

	minimap_width2.x = MINIMAP_WIDTH2;
	minimap_width2.y = MINIMAP_WIDTH2;
	vec.y = data->player->tile_pos.y - MINIMAP_NB_WALL;
	while (vec.y < data->player->tile_pos.y + MINIMAP_NB_WALL + 1)
	{
		vec.x = data->player->tile_pos.x - MINIMAP_NB_WALL;
		while (vec.x < data->player->tile_pos.x + MINIMAP_NB_WALL + 1)
		{
			draw_minimap_wall(data, vec.x, vec.y,
				get_tile_type(data, vec.x, vec.y));
			vec.x = vec.x + 1;
		}
		vec.y = vec.y + 1;
	}
	ft_circle(minimap_width2, 5,
		0xFF0000FF, data->image.map_img);
}
