/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:41:15 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/24 10:17:15 by matfranc         ###   ########.fr       */
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

static int	getpixelpos(int pos, int wall_size)
{
	return ((pos % (int)WALL_SIZE) * ((float)wall_size / WALL_SIZE));
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

static void	drawvline(t_vector line, int x, int pos, t_data *data, t_raycastHit *ray)
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
	stepx = getpixelpos(pos, wall_size);
	cleanline(0, line.x, x, data->image._3d);
	while (line.x < line.y && y < wall_size)
	{
		if (line.x > 0 || line.y < (int)data->image._3d->height - 1)
		{
			ft_pixel_put(data->image._3d, x, line.x,
				getpixelcolor(texture->pixels
					+ ((((int)y) * texture->width) + (int)stepx)
					* texture->bytes_per_pixel));
		}
		y += stepy;
		line.x = line.x + 1;
	}
	cleanline(line.y, WINDOW_HEIGHT, x, data->image._3d);
}

void	drawline3d(t_data *data, int x, t_raycastHit *ray)
{
	int			lineheight;
	t_vector	line;
	int			pos;

	pos = 0;
	lineheight = (int)((float)data->image._3d->height / ray->perp_wall_dist);
	line.x = (data->image._3d->height / 2.0) - (lineheight / 2.0);
	line.y = (data->image._3d->height / 2.0) + (lineheight / 2.0);
	drawvline(line, x, pos, data, ray);
}
