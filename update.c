/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:14:08 by lloison           #+#    #+#             */
/*   Updated: 2023/02/23 18:27:30 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	update_time(t_data *data)
{
	static double	last_update;
	double			time;

	if (last_update == 0)
	{
		last_update = mlx_get_time();
		time = last_update;
	}
	else
	{
		time = mlx_get_time();
		data->delta_time = time - last_update;
		last_update = time;
	}
	return (time);
}

static t_bool	handle_input(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(data->mlx);
		return (FALSE);
	}
	ft_movement(data);
	return (TRUE);
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
}

static void	handle_raycast(t_data *data)
{
	int			i;
	t_vector	v;
	t_vector	u;
	float		angle;
	float		angle_increment;

	v.x = 0;
	v.y = -1;
	ft_vector_rotation(&v, (float)data->player->angle);
	i = 0;
	angle = -PLAYER_FOV2;
	angle_increment = PLAYER_FOV * DOWN_SCALE / data->image._3d->width;
	while (i < (int)data->image._3d->width)
	{
		u.x = v.x;
		u.y = v.y;
		ft_vector_rotation(&u, angle);
		angle += angle_increment;
		render(data, raycast(data, u, angle * (M_PI / 180.0)), i);
		i += DOWN_SCALE;
	}
}

void	update(void *param)
{
	t_data	*data;
	double	time;

	data = param;
	time = update_time(data);
	if (!handle_input(data))
		return ;
	draw_minimap(data);
	handle_raycast(data);
	update_animation(data, time);
}
