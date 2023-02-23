/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:59:24 by lloison           #+#    #+#             */
/*   Updated: 2023/02/23 18:22:39 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	tile_pos_to_map_pos(t_pos tile_pos)
{
	t_vector	output;

	output.x = 0;
	output.y = 0;
	if (tile_pos.x != 0)
		output.x = (tile_pos.x) * WALL_SIZE;
	if (tile_pos.y != 0)
		output.y = (tile_pos.y) * WALL_SIZE;
	output.x += WALL_SIZE / 2;
	output.y += WALL_SIZE / 2;
	return (output);
}

t_pos	map_pos_to_tile_pos(t_vector map_pos)
{
	t_pos	output;

	output.x = truncf(map_pos.x / WALL_SIZE);
	output.y = truncf(map_pos.y / WALL_SIZE);
	return (output);
}

t_pos	pos(float x, float y)
{
	t_pos	output;

	output.x = x;
	output.y = y;
	return (output);
}

t_vector	v_pos(float x, float y)
{
	t_vector	output;

	output.x = x;
	output.y = y;
	return (output);
}

t_pos	*ptr_pos(float x, float y)
{
	t_pos	*output;

	output = malloc(sizeof(t_pos));
	if (!output)
		malloc_error();
	output->x = x;
	output->y = y;
	return (output);
}
