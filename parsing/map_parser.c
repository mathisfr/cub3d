/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:29:27 by lloison           #+#    #+#             */
/*   Updated: 2023/02/16 17:58:49 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map_parser_utils.h"

static int	open_file(char *filepath)
{
	int	fd;

	check_extension(filepath);
	fd = open(filepath, O_RDONLY);
	if (fd == -1 || fd == 0)
		system_error("PARSING: can't open input file");
	return (fd);
}

//Return a linked list of all data (only map for now)
static t_list	*get_data(int fd)
{
	t_list	*map_lines;
	char	*tmp_line;
	void	*tmp_node;

	map_lines = 0;
	tmp_line = get_next_line(fd);
	if (tmp_line == 0)
		parsing_error("file empty or malloc error");
	while (tmp_line)
	{
		check_line(tmp_line);
		remove_endl(tmp_line);
		tmp_node = ft_lstnew(tmp_line);
		if (!tmp_node)
			malloc_error();
		ft_lstadd_back(&map_lines, tmp_node);
		tmp_line = get_next_line(fd);
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
t_map	*parse_map(char *filepath)
{
	int		fd;
	t_list	*map_data;
	t_map	*map;

	fd = open_file(filepath);
	map_data = get_data(fd);
	map = data_to_map(map_data);
	ft_lstclear(&map_data, free);
	check_map(map);
	return (map);
}
