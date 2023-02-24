/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:22:10 by lloison           #+#    #+#             */
/*   Updated: 2023/02/23 18:25:47 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	inv_sqrt(float x)
{
	float	xhalf;
	int		i;

	xhalf = 0.5f * x;
	i = *(int *)&x;
	i = 0x5f3759df - (i >> 1);
	x = *(float *)&i;
	x = x * (1.5f - xhalf * x * x);
	return (x);
}

t_vector	normalize_vector(t_vector v)
{
	float	length;
	float	t;

	length = v.x * v.x + v.y * v.y;
	if (length == 0)
		return (v);
	t = inv_sqrt(length);
	v.x *= t;
	v.y *= t;
	return (v);
}
