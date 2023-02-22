/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:18:11 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/22 14:15:04 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_line(mlx_image_t *img, int begin_x, int begin_y, int end_x, int end_y, uint32_t color)
{
	double delta_x;
	double delta_y;
	double pixel_x;
	double pixel_y;
	int pixels;

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

void	ft_line2(mlx_image_t *img, int begin_x, int begin_y, int end_x, int end_y, uint32_t color)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		pixels;
	int		i;

	i = color & 0xFF;
	delta_x = end_x - begin_x;
	delta_y = end_y - begin_y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = begin_x;
	pixel_y = begin_y;
	while (pixels && i > 0)
	{
		ft_pixel_put(img, pixel_x, pixel_y, color);
		color -= 16777216;
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
		i--;
	}
}

void	draw_ray(t_data *data, t_map *map, t_pos map_pos, t_pos tile_pos, t_vector dir, int x)
{
	if (dir.x == 0 && dir.y == 0)
		return;
	//dir = normalize_vector(dir);
	float deltaDistX = (dir.x == 0) ? MAXFLOAT : fabs((1.0 / dir.x));
	float deltaDistY = (dir.y == 0) ? MAXFLOAT : fabs((1.0 / dir.y));
	int stepX;
	int stepY;
	float sideDistX = 0;
	float sideDistY = 0;

	// Nous indique si c'est un mur vertical ou horizontal
	int side;


	if(dir.x < 0)
	{
	  stepX = -1;
	  sideDistX = (int)map_pos.x % 50 / 50.0 * deltaDistX;
	}
	else
	{
	  stepX = 1;
	  sideDistX = (1 -(int)map_pos.x % 50 / 50.0) * deltaDistX;
	}
	if(dir.y < 0)
	{
	  stepY = -1;
	  sideDistY = (int)map_pos.y % 50 / 50.0 * deltaDistY;
	}
	else
	{
	  stepY = 1;
	  sideDistY = (1 - (int)map_pos.y % 50 / 50.0) * deltaDistY;
	}

	while (1)
	{
		// Si on arrive a une intersection ?
		if (sideDistX < sideDistY)
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
		// Check if ray has hit a wall
		if (map->map_arr[(int)tile_pos.y][(int)tile_pos.x] != '0')
			break;
	}
	float perpWallDist;

	// Si le mur et vertical au horizontal
	if (side == 0)
		perpWallDist = (sideDistX - deltaDistX);
	else
		perpWallDist = (sideDistY - deltaDistY);


	//perpWallDist = sqrt(pow(sideDistX, 2) + pow((sideDistY - deltaDistY), 2));
	t_pos	end_pos;
//
	end_pos.x = map_pos.x;
	end_pos.y = map_pos.y;

	float angle = atan2(dir.y, dir.x);

	//perpWallDist *= cos(angle);

	if (dir.x < 0)
		end_pos.x += perpWallDist * cos(angle) * WALL_SIZE;
	else
		end_pos.x += perpWallDist * cos(angle) * WALL_SIZE;
	if (dir.y < 0)
		end_pos.y += perpWallDist * sin(angle) * WALL_SIZE;
	else
		end_pos.y += perpWallDist * sin(angle) * WALL_SIZE;

	//printf("perpWallDist : %f\n", perpWallDist);
	//printf("sideDist %fx,%fy\n",sideDistX, sideDistY);
	//printf("x : %f\n", end_pos.x);
	//printf("y : %f\n", end_pos.y);

	//printf("angle : %f\n", angle * 180 / M_PI);

	//ft_line2(data->image.line,
	//	map_pos.x,
	//	map_pos.y,
	//	end_pos.x,
	//	end_pos.y,
	//	0xFFFFFFFF);


	perpWallDist = perpWallDist * fabs(sin((angle - (data->player->angle * M_PI / 180))));
	//printf("perp : %f\n", perpWallDist);

	//if ((int)perpWallDist != 0)
	int	drawloop = 0;
	t_raycastHit ray;
	ray.perpWallDist = perpWallDist;
	ray.pos.x = 0;
	ray.pos.y = 0;
	ray.texture = data->texture.wall_n;
	while (drawloop < DOWN_SCALE)
	{
		drawline3d(data, x, &ray);
		x++;
		drawloop++;
	}
	if (map->map_arr[(int)tile_pos.y][(int)tile_pos.x] == '2'
		&& perpWallDist < 1.5)
	{
		if (data->key_action == TRUE)
		{
			map->map_arr[(int)tile_pos.y][(int)tile_pos.x] = '0';
		}
	}
}
