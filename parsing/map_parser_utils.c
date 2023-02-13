/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:48:21 by lloison           #+#    #+#             */
/*   Updated: 2023/02/13 15:14:58 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_map_size(t_map *map, t_list *map_lines)
{
	t_list	*lst;
	int		max_x;
	int		cur_x;

	map->max_y_size = ft_lstsize(map_lines);
	lst = map_lines;
	max_x = 0;
	while (lst)
	{
		cur_x = ft_strlen((char *) lst->content);
		if (cur_x > max_x)
			max_x = cur_x;
		lst = lst->next;
	}
	map->max_x_size = max_x;
}

char	*copy_and_fill(char *line, int size)
{
	int		i;
	char	*output;

	i = 0;
	output = malloc(sizeof(char) * (size + 1));
	if (!output)
		malloc_error();
	output[size] = 0;
	while (i < size)
	{
		if (line[i] && line[i] != '\n')
			output[i] = line[i];
		else
			break ;
		i++;
	}
	while (i < size)
	{
		output[i] = ' ';
		i++;
	}
	return (output);
}

void	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'E' && line[i] != 'S'
			&& line[i] != 'W' && line [i] != '\n')
			parsing_error("Invalid character found");
		if (line[i] == '\n' && line[i + 1])
			parsing_error("Invalid character found");
		i++;
	}
}

void	remove_endl(char *line)
{
	int	length;

	length = ft_strlen(line);
	if (line[length - 1] == '\n')
		line[length - 1] = 0;
}

void	check_extension(char *line)
{
	int	length;

	length = ft_strlen(line);
	if (length <= 4)
		parsing_error("Filename is too short");
	if (line[length - 1] != 'b' || line[length - 2] != 'u'
		|| line[length - 3] != 'c' || line[length - 4] != '.')
		parsing_error("Filename must end with .cub");
}
