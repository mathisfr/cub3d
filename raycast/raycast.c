/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:58:58 by lloison           #+#    #+#             */
/*   Updated: 2023/02/22 15:07:46 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_deltaDist(t_vector dir, t_vector *deltaDist)
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

static t_pos	init_sideDist_step(t_data *data, t_vector dir,
	t_vector *sideDist, t_vector deltaDist)
{
	t_pos	step;

	if(dir.x < 0)
	{
		step.x = -1;
		sideDist->x = (int)data->player->map_pos.x % 50
	  		/ 50.0 * deltaDist.x;
	}
	else
	{
		step.x = 1;
		sideDist->x = (1 -(int)data->player->map_pos.x % 50 / 50.0)
	  	* deltaDist.x;
	}
	if(dir.y < 0)
	{
		step.y = -1;
		sideDist->y = (int)data->player->map_pos.y % 50 / 50.0
			* deltaDist.y;
	}
	else
	{
		step.y = 1;
		sideDist->y = (1 - (int)data->player->map_pos.y % 50 / 50.0)
			* deltaDist.y;
	}
	return (step);
}

static int	execute_dda(t_data *data, t_vector dir, t_vector *sideDist, t_vector deltaDist, t_pos *tile_pos)
{
	t_pos	step;
	int		side;

	step = init_sideDist_step(data, dir, sideDist, deltaDist);
	while (data->map->map_arr[tile_pos->y][tile_pos->x] != '0')
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
	}
	return (side);
}

static void	update_raycastHit(t_raycastHit *hit, t_data *data, float angle, t_vector dir)
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
	ft_line2(data->image.line,
		data->player->map_pos.x,
		data->player->map_pos.y,
		hit->pos.x,
		hit->pos.y,
		0xFFFFFFFF);
	hit->perpWallDist = hit->perpWallDist
		* fabs(sin((angle - (data->player->angle * M_PI / 180))));
}

t_raycastHit	raycast(t_data *data, t_vector dir, float angle)
{
	t_raycastHit	output;
	t_vector		deltaDist;
	t_vector		sideDist;
	t_pos			tile_pos;
	int				side;

	init_deltaDist(dir, &deltaDist);
	tile_pos.x = (int)data->player->tile_pos.x;
	tile_pos.y = (int)data->player->tile_pos.y;
	side = execute_dda(data, dir, &sideDist, deltaDist, &tile_pos);
	if (side == 0)
		output.perpWallDist = sideDist.x - deltaDist.x;
	else
		output.perpWallDist = sideDist.y - deltaDist.y;
	update_raycastHit(&output, data, angle, dir);
	if (side == 0 && dir.x > 0)
		output.side = LEFT;
	else if (side == 0 && dir.x < 0)
		output.side = RIGHT;
	else if (side == 1 && dir.y > 0)
		output.side = BOTTOM;
	else
		output.side = TOP;
	return (output);
}
