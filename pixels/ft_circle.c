/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:45:46 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/23 18:28:44 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawcircle(int xc, int yc, int x, int y,
	uint32_t color, mlx_image_t *image)
{
	ft_pixel_put(image, xc + x, yc + y, color);
	ft_pixel_put(image, xc - x, yc + y, color);
	ft_pixel_put(image, xc + x, yc - y, color);
	ft_pixel_put(image, xc - x, yc - y, color);
	ft_pixel_put(image, xc + y, yc + x, color);
	ft_pixel_put(image, xc - y, yc + x, color);
	ft_pixel_put(image, xc + y, yc - x, color);
	ft_pixel_put(image, xc - y, yc - x, color);
}

void	ft_circle(int xc, int yc, int r, uint32_t color, mlx_image_t *image)
{
	int	x;
	int	y;
	int	d;

	x = 0;
	y = r;
	d = 3 - 2 * r;
	drawcircle(xc, yc, x, y, color, image);
	while (y >= x)
	{
		x++;
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		drawcircle(xc, yc, x, y, color, image);
	}
}
