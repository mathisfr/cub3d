/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:47:05 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/24 09:52:52 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	set_dir_x(t_data *data, t_vector dir,
	t_vector *sideDist, t_vector deltaDist)
{
	int	x;

	x = 0;
	if (dir.x < 0)
	{
		x = -1;
		sideDist->x = (int)data->player->map_pos.x % (int)WALL_SIZE
			/ WALL_SIZE * deltaDist.x;
	}
	else
	{
		x = 1;
		sideDist->x = (1 -(int)data->player->map_pos.x % (int)WALL_SIZE
				/ WALL_SIZE) * deltaDist.x;
	}
	return (x);
}

static int	set_dir_y(t_data *data, t_vector dir,
	t_vector *sideDist, t_vector deltaDist)
{
	int	y;

	y = 0;
	if (dir.y < 0)
	{
		y = -1;
		sideDist->y = (int)data->player->map_pos.y % (int)WALL_SIZE / WALL_SIZE
			* deltaDist.y;
	}
	else
	{
		y = 1;
		sideDist->y = (1 - (int)data->player->map_pos.y % (int)WALL_SIZE
				/ WALL_SIZE) * deltaDist.y;
	}
	return (y);
}

static t_pos	init_sidedist_step(t_data *data, t_vector dir,
	t_vector *side_dist, t_vector delta_dist)
{
	t_pos	step;

	step.x = set_dir_x(data, dir, side_dist, delta_dist);
	step.y = set_dir_y(data, dir, side_dist, delta_dist);
	return (step);
}

int	execute_dda(t_data *data, t_dda *dda)
{
	t_pos	step;
	int		side;

	step = init_sidedist_step(data, dda->dir, dda->side_dist, dda->delta_dist);
	while (1)
	{
		if (dda->side_dist->x < dda->side_dist->y)
		{
			dda->side_dist->x += dda->delta_dist.x;
			dda->tile_pos.x += step.x;
			side = 0;
		}
		else
		{
			dda->side_dist->y += dda->delta_dist.y;
			dda->tile_pos.y += step.y;
			side = 1;
		}
		if (data->map->map_arr[dda->tile_pos.y][dda->tile_pos.x] == '1')
			break ;
		if (data->map->map_arr[dda->tile_pos.y][dda->tile_pos.x] == '2')
			return (2 + side);
	}
	return (side);
}
