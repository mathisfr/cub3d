/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:58:58 by lloison           #+#    #+#             */
/*   Updated: 2023/02/24 09:49:17 by matfranc         ###   ########.fr       */
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

static void	update_raycasthit(t_raycastHit *hit, t_data *data,
	float angle, t_vector dir)
{
	t_vector	line_start;
	t_vector	line_end;

	line_start.x = MINIMAP_WIDTH2;
	line_start.y = MINIMAP_WIDTH2;
	hit->pos.x = data->player->map_pos.x;
	hit->pos.y = data->player->map_pos.y;
	if (dir.x < 0)
		hit->pos.x += hit->perp_wall_dist * cos(angle) * WALL_SIZE;
	else
		hit->pos.x += hit->perp_wall_dist * cos(angle) * WALL_SIZE;
	if (dir.y < 0)
		hit->pos.y += hit->perp_wall_dist * sin(angle) * WALL_SIZE;
	else
		hit->pos.y += hit->perp_wall_dist * sin(angle) * WALL_SIZE;
	line_end.x = MINIMAP_WIDTH2 + ((hit->pos.x - data->player->map_pos.x)
			/ WALL_SIZE * MINIMAP_WIDTH / (float)(MINIMAP_NB_WALL * 2));
	line_end.y = MINIMAP_WIDTH2 + ((hit->pos.y - data->player->map_pos.y)
			/ WALL_SIZE * MINIMAP_WIDTH / (float)(MINIMAP_NB_WALL * 2));
	ft_line(data->image.map_img, line_start, line_end, 0xFFFFFFFF);
	hit->perp_wall_dist = hit->perp_wall_dist
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
	t_dda			dda;
	int				side;

	init_deltadist(dir, &delta_dist);
	dda.tile_pos.x = (int)data->player->tile_pos.x;
	dda.tile_pos.y = (int)data->player->tile_pos.y;
	dda.dir = dir;
	dda.side_dist = &side_dist;
	dda.delta_dist = delta_dist;
	side = execute_dda(data, &dda);
	if (side % 2 == 0)
		output.perp_wall_dist = side_dist.x - delta_dist.x;
	else
		output.perp_wall_dist = side_dist.y - delta_dist.y;
	update_raycasthit(&output, data, atan2(dir.y, dir.x), dir);
	output.side = get_hit_side(side, dir);
	return (output);
}
