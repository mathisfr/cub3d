/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:48:04 by lloison           #+#    #+#             */
/*   Updated: 2023/02/13 17:36:27 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_UTILS_H
# define MAP_PARSER_UTILS_H
# include "cub3d.h"

void	set_map_size(t_map *map, t_list *map_lines);
char	*copy_and_fill(char *line, int size);
void	check_line(char *line);
void	remove_endl(char *line);
void	check_extension(char *line);

#endif
