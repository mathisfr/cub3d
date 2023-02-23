/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:41:15 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/23 18:25:20 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	getpixelcolor(uint8_t *pixel)
{
	return (((pixel[0] << 0))
		| ((pixel[1] << 8))
		| ((pixel[2] << 16))
		| ((pixel[3] << 24)));
}

int	getpixelpos(int pos, int wall_size)
{
	return ((pos % (int)WALL_SIZE) * ((float)wall_size / WALL_SIZE));
}

void	cleanline(int start, int end, int x, mlx_image_t *img)
{
	while (start < end)
	{
		ft_pixel_put(img, x, start, (uint32_t)0x0);
		start++;
	}
}

void	drawvline(int start, int end, int x, t_data *data, t_raycastHit *ray)
{
	int				wall_size;
	float			y;
	float			stepy;
	float			stepx;
	int				pos;
	mlx_texture_t	*texture;


	y = 0;
	pos = 0;
	texture = NULL;
	if (ray->side == DOOR_X || ray->side == DOOR_Y)
	{
		texture = data->texture.door;
		if (ray->side == DOOR_Y)
			pos = ray->pos.x;
		else if (ray->side == DOOR_X)
			pos = ray->pos.y;
	}
	else if (ray->side == TOP || ray->side == BOTTOM)
	{
		pos = ray->pos.x;
		texture = data->texture.wall_n;
		if (ray->side == BOTTOM)
			texture = data->texture.wall_s;
	}
	else if (ray->side == LEFT || ray->side == RIGHT)
	{
		pos = ray->pos.y;
		texture = data->texture.wall_o;
		if (ray->side == RIGHT)
			texture = data->texture.wall_e;
	}
	wall_size = texture->width;
	stepy = (float)wall_size / (float)(end - start);
	stepx = getpixelpos(pos, wall_size);
	cleanline(0, start, x, data->image._3d);
	while (start < end && y < wall_size)
	{
		if (start > 0 || end < (int)data->image._3d->height - 1)
		{
			ft_pixel_put(data->image._3d, x, start,
				getpixelcolor(texture->pixels
					+ ((((int)y) * texture->width) + (int)stepx)
					* texture->bytes_per_pixel));
		}
		y += stepy;
		start++;
	}
	cleanline(end, WINDOW_HEIGHT, x, data->image._3d);
}

void	drawline3d(t_data *data, int x, t_raycastHit *ray)
{
	int	lineheight;
	int	start;
	int	end;

	lineheight = (int)((float)data->image._3d->height / ray->perpWallDist);
	start = (data->image._3d->height / 2.0) - (lineheight / 2.0);
	end = (data->image._3d->height / 2.0) + (lineheight / 2.0);
	drawvline(start, end, x, data, ray);
}
