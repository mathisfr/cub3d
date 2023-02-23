/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:58:58 by lloison           #+#    #+#             */
/*   Updated: 2023/02/23 18:37:20 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_deltadist(t_vector dir, t_vector *deltaDist)
{
	if (dir.x == 0)
		deltaDist->x = MAXFLOAT;
	else
		deltaDist->x = fabs(1.0 / dir.x);
	if (dir.y == 0)
		deltaDist->y = MAXFLOAT;
	else
		deltaDist->y = fabs(1.0 / dir.y);
}

static t_pos	init_sidedist_step(t_data *data, t_vector dir,
	t_vector *sideDist, t_vector deltaDist)
{
	t_pos	step;

	if (dir.x < 0)
	{
		step.x = -1;
		sideDist->x = (int)data->player->map_pos.x % (int)WALL_SIZE
			/ WALL_SIZE * deltaDist.x;
	}
	else
	{
		step.x = 1;
		sideDist->x = (1 -(int)data->player->map_pos.x % (int)WALL_SIZE
				/ WALL_SIZE) * deltaDist.x;
	}
	if (dir.y < 0)
	{
		step.y = -1;
		sideDist->y = (int)data->player->map_pos.y % (int)WALL_SIZE / WALL_SIZE
			* deltaDist.y;
	}
	else
	{
		step.y = 1;
		sideDist->y = (1 - (int)data->player->map_pos.y % (int)WALL_SIZE
				/ WALL_SIZE) * deltaDist.y;
	}
	return (step);
}

static int	execute_dda(t_data *data, t_vector dir,
	t_vector *sideDist, t_vector deltaDist, t_pos *tile_pos)
{
	t_pos	step;
	int		side;

	step = init_sidedist_step(data, dir, sideDist, deltaDist);
	while (1)
	{
		if (sideDist->x < sideDist->y)
		{
			sideDist->x += deltaDist.x;
			tile_pos->x += step.x;
			side = 0;
		}
		else
		{
			sideDist->y += deltaDist.y;
			tile_pos->y += step.y;
			side = 1;
		}
		if (data->map->map_arr[tile_pos->y][tile_pos->x] == '1')
			break ;
		if (data->map->map_arr[tile_pos->y][tile_pos->x] == '2')
			return (2 + side);
	}
	return (side);
}

static void	update_raycasthit(t_raycastHit *hit, t_data *data,
	float angle, t_vector dir)
{
	hit->pos.x = data->player->map_pos.x;
	hit->pos.y = data->player->map_pos.y;
	if (dir.x < 0)
		hit->pos.x += hit->perpWallDist * cos(angle) * WALL_SIZE;
	else
		hit->pos.x += hit->perpWallDist * cos(angle) * WALL_SIZE;
	if (dir.y < 0)
		hit->pos.y += hit->perpWallDist * sin(angle) * WALL_SIZE;
	else
		hit->pos.y += hit->perpWallDist * sin(angle) * WALL_SIZE;
	ft_line2(data->image.map_img,
		MINIMAP_WIDTH2,
		MINIMAP_WIDTH2,
		MINIMAP_WIDTH2 + ((hit->pos.x - data->player->map_pos.x) / WALL_SIZE
			* MINIMAP_WIDTH / (float)(MINIMAP_NB_WALL * 2)),
		MINIMAP_WIDTH2 + ((hit->pos.y - data->player->map_pos.y) / WALL_SIZE
			* MINIMAP_WIDTH / (float)(MINIMAP_NB_WALL * 2)),
		0xFFFFFFFF);
	hit->perpWallDist = hit->perpWallDist
		* fabs(sin((angle - (data->player->angle * M_PI / 180))));
}

static t_side	get_hit_side(int side, t_vector dir)
{
	if (side == 2)
		return (DOOR_X);
	if (side == 3)
		return (DOOR_Y);
	if (side == 0 && dir.x > 0)
		return (LEFT);
	if (side == 0 && dir.x < 0)
		return (RIGHT);
	if (side == 1 && dir.y > 0)
		return (BOTTOM);
	return (TOP);
}

t_raycastHit	raycast(t_data *data, t_vector dir)
{
	t_raycastHit	output;
	t_vector		delta_dist;
	t_vector		side_dist;
	t_pos			tile_pos;
	int				side;

	init_deltadist(dir, &delta_dist);
	tile_pos.x = (int)data->player->tile_pos.x;
	tile_pos.y = (int)data->player->tile_pos.y;
	side = execute_dda(data, dir, &side_dist, delta_dist, &tile_pos);
	if (side % 2 == 0)
		output.perpWallDist = side_dist.x - delta_dist.x;
	else
		output.perpWallDist = side_dist.y - delta_dist.y;
	update_raycasthit(&output, data, atan2(dir.y, dir.x), dir);
	output.side = get_hit_side(side, dir);
	return (output);
}
