/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:41:15 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/22 13:41:19 by matfranc         ###   ########.fr       */
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

int	getpixelpos(int x, int wall_size)
{
	float tmp = x % (int)WALL_SIZE;
	tmp *= (float)wall_size / WALL_SIZE;
	return tmp;
	//return ((int)(((int)x % (int)WALL_SIZE) * (WALL_SIZE / (float)wall_size)));
}

void	cleanline(int start, int end, int x, mlx_image_t *img)
{
	while (start < end)
	{
		ft_pixel_put(img, x, start, (uint32_t)0x0);
		start++;
	}
}

void	drawvline(int start, int end, int x, t_data *data)
{
	int		wall_size;
	float	y;
	float	stepy;
	int		stepx;

	y = 0;
	wall_size = data->texture.wall_n->width;
	stepy = (float)wall_size / (float)(end - start);
	stepx = getpixelpos(x, wall_size);
	cleanline(0, start, x, data->image._3d);
	while (start < end && y < wall_size)
	{
		ft_pixel_put(data->image._3d, x, start, getpixelcolor(data->texture.wall_n->pixels + ((((int)y) * data->texture.wall_n->width) + stepx) * data->texture.wall_n->bytes_per_pixel));
		y += stepy;
		start++;
	}
	cleanline(end, WINDOW_HEIGHT, x, data->image._3d);
}

void	drawline3d(t_data *data, int *x, int *side, float *perpWallDist)
{

	int lineheight;
	int start;
	int end;

	// Je divise la distance par la hauteur de notre fenetre
	if (*perpWallDist < 0.5)
		lineheight = data->image._3d->height;
	else
		lineheight = (int)((float)data->image._3d->height / *perpWallDist);

	// On commence à dessiner à la moitier de la fenetre et
	// à la moitier de la hauteur du mur pour centrer
	start = (data->image._3d->height / 2.0) - (lineheight / 2.0);
	// Si on est en dehors de l'ecran je met start à zero
	// pour pas qu'il dessiner pour rien dehors
	if (start < 0)
		start = 0;

	// Pratiquement comme start
	end = (data->image._3d->height / 2.0) + (lineheight / 2.0);
	if (end >= (int)data->image._3d->height)
		end = data->image._3d->height - 1;

	// Change de couleur si le murs est vertical ou horizontal
	// X est l'axe horizontal de là où on dessine
	if (*side == 0)
		drawvline(start, end, *x, data); // ft_line(data->_3d, *x, start, *x, end, 0xFFFFFF00);
	else
		drawvline(start, end, *x, data);
		//ft_line(data->_3d, *x, start, *x, end, 0xFF00FFFF);
}
