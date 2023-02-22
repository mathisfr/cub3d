/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:14:08 by lloison           #+#    #+#             */
/*   Updated: 2023/02/22 14:57:25 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_input(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	ft_movement(data);
}

static void	render(t_data *data, t_raycastHit hit, int x)
{
	int	drawloop;

	drawloop = 0;
	while (drawloop < DOWN_SCALE)
	{
		drawline3d(data, x, &hit);
		x++;
		drawloop++;
	}
	if (data->map->map_arr[(int)data->player->tile_pos.y][(int)data->player->tile_pos.x] == '2'
		&& hit.perpWallDist < 1.5)
	{
		if (data->key_action == TRUE)
		{
			data->map->map_arr[(int)data->player->tile_pos.y][(int)data->player->tile_pos.x] = '0';
		}
	}
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
		render(data, raycast(data, u, angle * (M_PI / 180.0)), i);
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
