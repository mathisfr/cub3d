/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:48:04 by lloison           #+#    #+#             */
/*   Updated: 2023/02/13 15:15:22 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_UTILS_H
# define MAP_PARSER_UTILS_H

void	set_map_size(t_map *map, t_list *map_lines);
char	*copy_and_fill(char *line, int size);
void	check_line(char *line);
void	remove_endl(char *line);
void	check_extension(char *line);

#endif