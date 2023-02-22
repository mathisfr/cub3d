/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:14:08 by lloison           #+#    #+#             */
/*   Updated: 2023/02/22 13:20:20 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_input(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	ft_movement(data);
}

static void	handle_raycast(t_data *data)
{
	int			i;
	int			width;
	t_vector 	v;
	t_vector	u;
	float		angle;
	float		angle_increment;

	ft_memset(data->image.line->pixels, 1, data->image.line->width * data->image.line->height * sizeof(int32_t));
	ft_memset(data->image._3d->pixels, 1, data->image._3d->width * data->image._3d->height * sizeof(int32_t));

	v.x = 0;
	v.y = -1;
	ft_vector_rotation(&v, (float)data->player->angle);
	i = 0;
	width = (int)data->image._3d->width;
	angle = -PLAYER_FOV2;
	angle_increment = PLAYER_FOV * DOWN_SCALE / data->image._3d->width;
	while (i < width)
	{
		u.x = v.x;
		u.y = v.y;
		ft_vector_rotation(&u, angle);
		angle += angle_increment;
		draw_ray(data, data->map, data->player->map_pos, data->player->tile_pos, u, i);
		i += DOWN_SCALE;
	}
}

//static void	old_raycast(t_data *data)
//{
//	t_vector v;
//	t_vector u;
//	u.x = 0;
//	u.y = -1;
//	ft_vector_rotation(&u, (float)data->player->angle);
//	ft_memset(data->image.line->pixels, 1, data->image.line->width * data->image.line->height * sizeof(int32_t));
//	float angle = -(PLAYER_FOV / 2.0);
//	ft_memset(data->image._3d->pixels, 1, data->image._3d->width * data->image._3d->height * sizeof(int32_t));
//	for(int i = 0; i < (int)data->image._3d->width; i += DOWN_SCALE)
//	{
//		v.x = u.x;
//		v.y = u.y;
//		angle += (PLAYER_FOV / 2.0) / (data->image._3d->width / (2 * DOWN_SCALE));
//		ft_vector_rotation(&v, angle);
//		draw_ray(data, data->map, data->player->map_pos, data->player->tile_pos, v, i);
//	}
//}

void update(void* param)
{
	t_data	*data;

	data = param;
	handle_input(data);
	handle_raycast(data);
}