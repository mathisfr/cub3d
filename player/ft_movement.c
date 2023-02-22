/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:02:14 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/22 15:50:25 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_vector_rotation(t_vector *vec, float angle)
{
	t_vector	new_vec;
	float		cosa;
	float		sina;

	while (angle < 0)
		angle += 360; 
	angle = angle * (M_PI / 180);
	cosa = cos(angle);
	sina = sin(angle);
	new_vec.x = vec->x * cosa - vec->y * sina;
	new_vec.y = vec->x * sina + vec->y * cosa;
	vec->x = new_vec.x;
	vec->y = new_vec.y;
}

static void	move_and_rotate(t_data *data)
{
	data->image.player->instances[0].y += roundf(data->player->movement.y);
	data->image.player->instances[0].x += roundf(data->player->movement.x);
}

static void	get_movement_input(t_data *data)
{
	int			angle_save;

	angle_save = data->player->angle;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		data->player->movement.y = -1;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		data->player->movement.y = 1;
	else
		data->player->movement.y = 0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		data->player->movement.x = -1;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		data->player->movement.x = 1;
	else
		data->player->movement.x = 0;
	data->player->movement.x *= PLAYER_SPEED;
	data->player->movement.y *= PLAYER_SPEED;
}

void	ft_movement(t_data *data)
{
	get_movement_input(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->player->angle += -ROTATE_SPEED;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->player->angle += ROTATE_SPEED;
	ft_vector_rotation(&data->player->movement, (float)data->player->angle);
	update_player(data->player,
		pos(data->image.player->instances[0].x, data->image.player->instances[0].y), data->map);
	move_and_rotate(data);
}
