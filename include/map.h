/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:18:00 by lloison           #+#    #+#             */
/*   Updated: 2023/02/21 14:12:29 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "MLX42/MLX42.h"

typedef struct s_texture
{
	mlx_texture_t	*wall_n;
	mlx_texture_t	*wall_s;
	mlx_texture_t	*wall_e;
	mlx_texture_t	*wall_o;
}	t_texture;

typedef struct s_map
{
	char	**map_arr;
	int		max_x_size;
	int		max_y_size;
}	t_map;

void	check_map(t_map *map);
t_map	*parse_map(char *filepath);

#endif
