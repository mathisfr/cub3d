/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:41:15 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/24 14:19:59 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	getpixelcolor(uint8_t *pixel)
{
	return (((pixel[0] << 0))
		| ((pixel[1] << 8))
		| ((pixel[2] << 16))
		| ((pixel[3] << 24)));
}

static void	cleanline(int start, int end, int x, mlx_image_t *img)
{
	while (start < end)
	{
		ft_pixel_put(img, x, start, (uint32_t)0x0);
		start++;
	}
}

mlx_texture_t	*set_texture(t_data *data, t_raycastHit *ray, int *pos)
{
	mlx_texture_t	*texture;

	if (ray->side == DOOR_X || ray->side == DOOR_Y)
	{
		texture = data->texture.door;
		if (ray->side == DOOR_Y)
			*pos = ray->pos.x;
		else if (ray->side == DOOR_X)
			*pos = ray->pos.y;
	}
	else if (ray->side == TOP || ray->side == BOTTOM)
	{
		*pos = ray->pos.x;
		texture = data->texture.wall_n;
		if (ray->side == BOTTOM)
			texture = data->texture.wall_s;
	}
	else
	{
		*pos = ray->pos.y;
		texture = data->texture.wall_o;
		if (ray->side == RIGHT)
			texture = data->texture.wall_e;
	}
	return (texture);
}

static void	drawvline(t_vector line, int pos, t_data *data, t_raycastHit *ray)
{
	int				wall_size;
	float			stepy;
	float			stepx;
	float			y;
	mlx_texture_t	*texture;

	y = 0;
	texture = set_texture(data, ray, &pos);
	wall_size = texture->width;
	stepy = (float)wall_size / (float)(line.y - line.x);
	stepx = (pos % (int)WALL_SIZE) * ((float)wall_size / WALL_SIZE);
	cleanline(0, line.x, ray->x, data->image._3d);
	while (line.x < line.y && y < wall_size)
	{
		if (line.x > 0 || line.y < (int)data->image._3d->height - 1)
		{
			ft_pixel_put(data->image._3d, ray->x, line.x,
				getpixelcolor(texture->pixels
					+ ((((int)y) * texture->width) + (int)stepx)
					* texture->bytes_per_pixel));
		}
		y += stepy;
		line.x = line.x + 1;
	}
	cleanline(line.y, WINDOW_HEIGHT, ray->x, data->image._3d);
}

void	drawline3d(t_data *data, t_raycastHit *ray)
{
	int			lineheight;
	t_vector	line;
	int			pos;

	pos = 0;
	lineheight = (int)((float)data->image._3d->height / ray->perp_wall_dist);
	line.x = (data->image._3d->height / 2.0) - (lineheight / 2.0);
	line.y = (data->image._3d->height / 2.0) + (lineheight / 2.0);
	drawvline(line, pos, data, ray);
}
