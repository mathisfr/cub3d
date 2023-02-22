/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:12:02 by lloison           #+#    #+#             */
/*   Updated: 2023/02/21 19:31:08 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
#define DATA_H

#include "player.h"
#include "map.h"
#include "MLX42/MLX42.h"

typedef struct s_data
{
	mlx_t		*mlx;
	t_player	*player;
	t_bool		key_action;
	t_map		*map;
	mlx_image_t	*img;
	mlx_image_t *_3d;
	mlx_image_t *background;
	mlx_image_t	*vec_dir;
	mlx_image_t	*line;
	t_texture	texture;
}	t_data;

t_data	*init_data(mlx_t *mlx, char *filename);
void	free_data(t_data *data);
void	drawline3d(t_data *data, int *x, int *side, float *perpWallDist);
void	ft_line2(mlx_image_t *img, int begin_x, int begin_y, int end_x, int end_y, uint32_t color);

#endif
