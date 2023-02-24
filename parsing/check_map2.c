/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:56:14 by lloison           #+#    #+#             */
/*   Updated: 2023/02/24 17:22:11 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	is_empty(char c)
{
	if (c == '0' || c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (TRUE);
	return (FALSE);
}

static t_bool	is_door_valid(t_map *map, int x, int y)
{
	if (map->map_arr[y - 1][x] == '1' && map->map_arr[y + 1][x] == '1'
		&& is_empty(map->map_arr[y][x - 1])
		&& is_empty(map->map_arr[y][x + 1]))
		return (TRUE);
	if (is_empty(map->map_arr[y - 1][x]) && is_empty(map->map_arr[y + 1][x])
		&& map->map_arr[y][x - 1] == '1' && map->map_arr[y][x + 1] == '1')
		return (TRUE);
	return (FALSE);
}

void	check_doors(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->max_y_size)
	{
		x = 0;
		while (x < map->max_x_size)
		{
			if (map->map_arr[y][x] == '2')
				if (!is_door_valid(map, x, y))
					parsing_error("Invalid door position.");
			x++;
		}
		y++;
	}
}
