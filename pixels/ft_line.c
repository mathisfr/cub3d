/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:18:11 by matfranc          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/02/15 18:50:10 by matfranc         ###   ########.fr       */
=======
/*   Updated: 2023/02/15 19:01:48 by lloison          ###   ########.fr       */
>>>>>>> 5711a2f93486cdb14db9d64c60e1e046dc251a7e
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_line(mlx_image_t *img, int begin_x, int begin_y, int end_x, int end_y, uint32_t color)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		pixels;

	delta_x = end_x - begin_x;
	delta_y = end_y - begin_y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = begin_x;
	pixel_y = begin_y;
	while (pixels)
	{
		ft_pixel_put(img, pixel_x, pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}

void	draw_ray(t_data *data, t_map *map, t_pos map_pos, t_pos tile_pos, t_vector dir)
{
	float deltaDistX = (dir.x == 0) ? MAXFLOAT : abs((int)(1 / dir.x));
    float deltaDistY = (dir.y == 0) ? MAXFLOAT : abs((int)(1 / dir.y));
    int stepX;
    int stepY;
	float sideDistX = 0;
	float sideDistY = 0;
	int side;

	if(dir.x < 0)
    {
      stepX = -1;
	  sideDistX = 0 * deltaDistX;
    }
    else
    {
      stepX = 1;
	  sideDistX = 1.0 * deltaDistX;
    }
    if(dir.y < 0)
    {
      stepY = -1;
	  sideDistY = 0 * deltaDistY;
    }
    else
    {
      stepY = 1;
	  sideDistY = 1.0 * deltaDistY;
    }

	while (1)
	{
		if(sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          tile_pos.x += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          tile_pos.y += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if(map->map_arr[(int)tile_pos.y][(int)tile_pos.x] != '0')
			break;
	}
	float perpWallDist;

	if(side == 0) perpWallDist = (sideDistX - deltaDistX);
    else          perpWallDist = (sideDistY - deltaDistY);

	printf("perpWallDist : %f\n", perpWallDist);
<<<<<<< HEAD
	printf("x : %f\n", (perpWallDist * dir.x) - (int)map_pos.x % 50 / 50.0);
	printf("y : %f\n", (perpWallDist * dir.y) - (int)map_pos.y % 50 / 50.0);

	ft_line(data->line,
=======
	printf("x : %f\n", (int)map_pos.x % 50 / 50.0);
	printf("y : %f\n", (int)map_pos.y % 50 / 50.0);
	
	ft_line(data->line, 
>>>>>>> 5711a2f93486cdb14db9d64c60e1e046dc251a7e
		map_pos.x,
		map_pos.y,
		map_pos.x + ((perpWallDist * dir.x) - (int)map_pos.y % 50 / 50.0) * WALL_SIZE,
		map_pos.y + ((perpWallDist * dir.y) - (int)map_pos.y % 50 / 50.0) * WALL_SIZE,
		0xFFFFFFFF);

	// si side = 0 alors faut prendre map_pos x pour le decalage.
	// adapter le perpWall en fonction de l'angle ???
}
