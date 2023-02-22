/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:14:38 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/22 14:42:36 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft_e.h"
# include "data.h"
# include "defines.h"
# include "map.h"
# include "player.h"
# include "vector.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <math.h>
# include "MLX42/MLX42.h"

// pixels
void	ft_pixel_put(mlx_image_t *image,
			uint32_t x, uint32_t y, uint32_t color);
void	ft_rectangle(int x, int y, int sx, int sy, uint32_t color, mlx_image_t *image);
void	ft_draw_map(t_map *map, int color, mlx_image_t* img);
void	circleBres(int xc, int yc, int r, uint32_t color, mlx_image_t *image);
void	ft_line(mlx_image_t *img, int begin_x, int begin_y, int end_x, int end_y, uint32_t color);
void	ft_line2(mlx_image_t *img, int begin_x, int begin_y, int end_x, int end_y, uint32_t color);
t_raycastHit	raycast(t_data *data, t_vector dir, float angle);

// player
void	ft_movement(t_data *data);

/* - - - - - error.c - - - - - */
void			parsing_error(char *message);
void			system_error(char *prompt);
void			malloc_error(void);

void update(void* param);

#endif
