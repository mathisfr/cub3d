/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:45:46 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/24 08:52:35 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	drawcircle(t_vector start, t_vector shift,
	uint32_t color, mlx_image_t *image)
{
	ft_pixel_put(image, start.x + shift.x, start.y + shift.y, color);
	ft_pixel_put(image, start.x - shift.x, start.y + shift.y, color);
	ft_pixel_put(image, start.x + shift.x, start.y - shift.y, color);
	ft_pixel_put(image, start.x - shift.x, start.y - shift.y, color);
	ft_pixel_put(image, start.x + shift.y, start.y + shift.x, color);
	ft_pixel_put(image, start.x - shift.y, start.y + shift.x, color);
	ft_pixel_put(image, start.x + shift.y, start.y - shift.x, color);
	ft_pixel_put(image, start.x - shift.y, start.y - shift.x, color);
}

void	ft_circle(t_vector vec, int r, uint32_t color, mlx_image_t *image)
{
	t_vector	shift;
	int			d;

	shift.x = 0;
	shift.y = r;
	d = 3 - 2 * r;
	drawcircle(vec, shift, color, image);
	while (shift.y >= shift.x)
	{
		shift.x = shift.x + 1;
		if (d > 0)
		{
			shift.y = shift.y - 1;
			d = d + 4 * (shift.x - shift.y) + 10;
		}
		else
			d = d + 4 * shift.x + 6;
		drawcircle(vec, shift, color, image);
	}
}
