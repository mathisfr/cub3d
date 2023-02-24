/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:18:11 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/24 09:28:08 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_line(mlx_image_t *img, t_vector start, t_vector end, uint32_t color)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		loop[2];

	loop[1] = color & 0xFF;
	delta_x = end.x - start.x;
	delta_y = end.y - start.y;
	loop[0] = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= loop[0];
	delta_y /= loop[0];
	pixel_x = start.x;
	pixel_y = start.y;
	while (loop[0] && loop[1] > 0)
	{
		ft_pixel_put(img, pixel_x, pixel_y, color);
		color -= 16777216 * 2;
		pixel_x += delta_x;
		pixel_y += delta_y;
		if (color >> 24 == 1)
			return ;
		--loop[0];
		loop[1]--;
	}
}
