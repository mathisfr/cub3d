/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:57:16 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/23 18:34:08 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rectangle(int x, int y, int sx, int sy, uint32_t color, mlx_image_t *image)
{
	int	i;
	int	j;

	i = 0;
	while (i < sy)
	{
		j = 0;
		while (j < sx)
		{
			ft_pixel_put(image, j + x, i + y, color);
			j++;
		}
		i++;
	}
}

static int	minimap_distance(int x, int y)
{
	return ((int)sqrt(pow(abs(y - MINIMAP_WIDTH2), 2)
			+ pow(abs(x - MINIMAP_WIDTH2), 2)));
}

void	ft_minimap_rectangle(int x, int y, int sx, int sy, uint32_t color, mlx_image_t *image)
{
	int	i;
	int	j;

	i = 0;
	while (i < sy)
	{
		j = 0;
		while (j < sx)
		{
			if (minimap_distance(j + x, i + y) < MINIMAP_WIDTH2)
				ft_pixel_put(image, j + x, i + y, color);
			j++;
		}
		i++;
	}
}
