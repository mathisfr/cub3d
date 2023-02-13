/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:57:16 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/13 16:26:38 by matfranc         ###   ########.fr       */
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
