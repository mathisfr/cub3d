/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:18:00 by lloison           #+#    #+#             */
/*   Updated: 2023/02/13 16:14:17 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_map
{
	char	**map_arr;
	int		max_x_size;
	int		max_y_size;
}	t_map;

void	check_map(t_map *map);
t_map	*parse_map(char *filepath);

#endif