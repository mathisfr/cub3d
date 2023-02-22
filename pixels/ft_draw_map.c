/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:39:42 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/22 13:50:22 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_map(t_map *map, int color, mlx_image_t* img)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->max_y_size)
	{
		j = 0;
		while (j < map->max_x_size)
		{
			if (map->map_arr[i][j] == '1')
				ft_rectangle(j * WALL_SIZE, i * WALL_SIZE, WALL_SIZE, WALL_SIZE,color, img);
			else if (map->map_arr[i][j] == '2')
				ft_rectangle(j * WALL_SIZE, i * WALL_SIZE, WALL_SIZE, WALL_SIZE, 0xFF0000FF, img);
			j++;
		}
		i++;
	}
}
