/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:29:27 by lloison           #+#    #+#             */
/*   Updated: 2023/02/25 15:02:22 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map_parser_utils.h"

//Return a linked list of all data (only map for now)
static t_list	*get_data(int fd)
{
	t_list	*map_lines;
	char	*tmp_line;
	void	*tmp_node;
	int		i;

	map_lines = 0;
	tmp_line = get_next_line(fd);
	if (tmp_line == 0)
		parsing_error("file empty or malloc error");
	i = 1;
	while (tmp_line)
	{
		if (ft_strlen(tmp_line) > 100 || i > 50)
			parsing_error("map is too big");
		check_line(tmp_line);
		remove_endl(tmp_line);
		tmp_node = ft_lstnew(tmp_line);
		if (!tmp_node)
			malloc_error();
		ft_lstadd_back(&map_lines, tmp_node);
		tmp_line = get_next_line(fd);
		i++;
	}
	return (map_lines);
}

//Create a 2d array in map->map_arr correspond to the linked list
static t_map	*data_to_map(t_list *map_lines)
{
	t_map	*map;
	int		i;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		malloc_error();
	set_map_size(map, map_lines);
	map->map_arr = malloc(sizeof(char *) * map->max_y_size);
	if (!map->map_arr)
		malloc_error();
	i = 0;
	while (i < map->max_y_size)
	{
		map->map_arr[i] = copy_and_fill(map_lines->content, map->max_x_size);
		i++;
		map_lines = map_lines->next;
	}
	return (map);
}

//Parse the map
t_map	*parse_map(int fd)
{
	t_list	*map_data;
	t_map	*map;

	map_data = get_data(fd);
	map = data_to_map(map_data);
	ft_lstclear(&map_data, free);
	check_map(map);
	return (map);
}
