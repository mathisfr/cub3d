/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:57:16 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/24 09:58:09 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rectangle(t_vector start, t_vector end,
						uint32_t color, mlx_image_t *image)
{
	int	i;
	int	j;

	i = 0;
	while (i < end.y)
	{
		j = 0;
		while (j < end.x)
		{
			ft_pixel_put(image, j + start.x, i + start.y, color);
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

void	ft_minimap_rectangle(t_vector start, t_vector end,
	uint32_t color, mlx_image_t *image)
{
	int	i;
	int	j;

	i = 0;
	while (i < end.y)
	{
		j = 0;
		while (j < end.x)
		{
			if (minimap_distance(j + start.x, i + start.y) < MINIMAP_WIDTH2)
				ft_pixel_put(image, j + start.x, i + start.y, color);
			j++;
		}
		i++;
	}
}
