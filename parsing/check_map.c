/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:27:33 by lloison           #+#    #+#             */
/*   Updated: 2023/02/23 18:41:45 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Check the border of the map to check for a 0
static void	check_borders(t_map *map)
{
	int	x;

	x = -1;
	while (++x < map->max_x_size)
		if ((map->map_arr[0][x] != ' '
			&& (map->map_arr[0][x] != '1' && map->map_arr[0][x] != '2'))
			|| (map->map_arr[map->max_y_size - 1][x] != ' '
				&& (map->map_arr[map->max_y_size - 1][x] != '1'
					&& map->map_arr[map->max_y_size - 1][x] != '2')))
			parsing_error("Map is not enclosed");
	x = -1;
	while (++x < map->max_y_size)
		if ((map->map_arr[x][0] != ' ' && map->map_arr[x][0] != '1'
			&& map->map_arr[x][0] != '2')
			|| (map->map_arr[x][map->max_x_size - 1] != ' '
				&& (map->map_arr[x][map->max_x_size - 1] != '1'
					&& map->map_arr[x][map->max_x_size - 1] != '2')))
			parsing_error("Map is not enclosed");
}

//Check for the 4 adjacent tile if they are ground
static void	check_adjacent(t_map *map, int x, int y)
{
	if (y != 0)
		if (map->map_arr[y - 1][x] != ' ' && (map->map_arr[y - 1][x] != '1'
			&& map->map_arr[y - 1][x] != '2'))
			parsing_error("Map is not enclosed");
	if (y < map->max_y_size - 1)
		if (map->map_arr[y + 1][x] != ' ' && (map->map_arr[y + 1][x] != '1'
			&& map->map_arr[y + 1][x] != '2'))
			parsing_error("Map is not enclosed");
	if (x != 0)
		if (map->map_arr[y][x - 1] != ' ' && (map->map_arr[y][x - 1] != '1'
			&& map->map_arr[y][x - 1] != '2'))
			parsing_error("Map is not enclosed");
	if (x < map->max_x_size - 1)
		if (map->map_arr[y][x + 1] != ' ' && (map->map_arr[y][x + 1] != '1'
			&& map->map_arr[y][x + 1] != '2'))
			parsing_error("Map is not enclosed");
}

//Check for every space if there is a ground adjacent
static void	check_spaces(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->max_y_size)
	{
		x = 0;
		while (x < map->max_x_size)
		{
			if (map->map_arr[y][x] == ' ')
				check_adjacent(map, x, y);
			x++;
		}
		y++;
	}
}

//Check for player character if they are at least one
static void	check_player(t_map *map)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (y < map->max_y_size)
	{
		x = 0;
		while (x < map->max_x_size)
		{
			if (map->map_arr[y][x] == 'N' || map->map_arr[y][x] == 'S'
				|| map->map_arr[y][x] == 'E' || map->map_arr[y][x] == 'W')
				count++;
			x++;
		}
		y++;
	}
	if (count == 0)
		parsing_error("No player found in map");
	if (count > 1)
		parsing_error("Too many player symbol found in map");
}

//Check if the map is valid
void	check_map(t_map *map)
{
	check_borders(map);
	check_spaces(map);
	check_player(map);
	check_doors(map);
}
