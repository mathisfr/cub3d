/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:14:38 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/14 16:42:31 by lloison          ###   ########.fr       */
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
# include <fcntl.h>
# include <math.h>
# include "MLX42/MLX42.h"

// pixels
void	ft_pixel_put(mlx_image_t *image,
			uint32_t x, uint32_t y, uint32_t color);
void	ft_rectangle(int x, int y, int sx, int sy, uint32_t color, mlx_image_t *image);
void	ft_draw_map(t_map *map, int color, mlx_image_t* img);
void	circleBres(int xc, int yc, int r, uint32_t color, mlx_image_t *image);

/* - - - - - error.c - - - - - */
void			parsing_error(char *message);
void			system_error(char *prompt);
void			malloc_error(void);

#endif
