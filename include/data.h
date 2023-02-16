/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:12:02 by lloison           #+#    #+#             */
/*   Updated: 2023/02/15 20:51:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
#define DATA_H

#include "player.h"
#include "map.h"
#include "MLX42/MLX42.h"

typedef struct s_data
{
	mlx_t *mlx;
	t_player *player;
	t_map *map;
	mlx_image_t *_3d;
	mlx_image_t *img;
	mlx_image_t *vec_dir;
	mlx_image_t *line;
} t_data;

t_data *init_data(mlx_t *mlx, char *filename);
void free_data(t_data *data);

#endif
