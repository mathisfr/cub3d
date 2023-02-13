/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:13:48 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/13 16:57:41 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_pixel_put(mlx_image_t *image, uint32_t x, uint32_t y, uint32_t color)
{
	uint8_t	*dst;
	int		bpp;

	bpp = sizeof(int32_t);
	dst = NULL;
	if ((x >= 0 && x < WINDOW_WIDTH) || (y >= 0 && y < WINDOW_HEIGHT))
		dst = image->pixels + ((((y) * image->width * bpp) + (x * bpp)));
	if (dst)
		*(uint32_t *)dst = color;
}
