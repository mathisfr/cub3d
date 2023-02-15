/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:02:14 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/15 17:27:24 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_vector_rotation(t_vector *vec, int *angle)
{
	t_vector	new_vec;
	float		_angle;

	if (*angle < 0)
		*angle = 359;
	else if (*angle > 359)
		*angle = 0;
	_angle = *angle * (M_PI / 180);
	new_vec.x = vec->x * cos(_angle) - vec->y * sin(_angle);
	new_vec.y = vec->x * sin(_angle) + vec->y * cos(_angle);
	vec->x = new_vec.x;
	vec->y = new_vec.y;
}

static void	set_rotation(t_data *data, int *angle_save)
{
	data->img->instances[0].y += data->player->movement.y;
	data->img->instances[0].x += data->player->movement.x;
	data->vec_dir->instances[0].y = data->img->instances[0].y;
	data->vec_dir->instances[0].x = data->img->instances[0].x;
	data->player->dir.x = data->player->movement.x * ((VEC_LEN / 2) / MOVE_SPEED);
	data->player->dir.y = data->player->movement.y * ((VEC_LEN / 2) / MOVE_SPEED);
	if (*angle_save != data->player->angle)
	{
		ft_memset(data->vec_dir->pixels, 1,
			data->vec_dir->width * data->vec_dir->height * sizeof(int32_t));
		ft_line(data->vec_dir, VEC_LEN / 2, VEC_LEN / 2, (VEC_LEN / 2) + data->player->dir.x, (VEC_LEN / 2) + data->player->dir.y, 0xFF0000FF);
	}
}

void	ft_movement(t_data *data)
{
	int			angle_save;

	angle_save = data->player->angle;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		data->player->movement.y = -MOVE_SPEED;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		data->player->movement.y = MOVE_SPEED;
	else
		data->player->movement.y = 0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		data->player->movement.x = -MOVE_SPEED;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		data->player->movement.x = MOVE_SPEED;
	else
		data->player->movement.x = 0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->player->angle += -ROTATE_SPEED;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->player->angle += ROTATE_SPEED;
	ft_vector_rotation(&data->player->movement, &data->player->angle);
	update_player(data->player,
		pos(data->img->instances[0].x, data->img->instances[0].y), data->map);
	set_rotation(data, &angle_save);
}
