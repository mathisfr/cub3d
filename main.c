/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:59:09 by lloison           #+#    #+#             */
/*   Updated: 2023/02/23 14:19:26 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "cub3d.h"

void look_mouse(double xpos, double ypos, void *param)
{
	t_data *data;
	
	(void) ypos;
	data = (t_data *)param;
	if (xpos > 0 && xpos < WINDOW_WIDTH && xpos != WINDOW_WIDTH / 2)
	{
		if (xpos > WINDOW_WIDTH / 2)
			data->player->angle += ((xpos - (WINDOW_WIDTH / 2)) * SENSITIVITY * data->delta_time * 20.0);
		else if (xpos < WINDOW_WIDTH / 2)
			data->player->angle -= (((WINDOW_WIDTH / 2) - xpos) * SENSITIVITY * data->delta_time * 20.0);
		mlx_set_mouse_pos(data->mlx, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	}
}

void key_action(mlx_key_data_t keydata, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (keydata.action == MLX_PRESS
		&& keydata.key == MLX_KEY_ENTER)
		data->key_action = true;
	if (keydata.action == MLX_RELEASE
		&& keydata.key == MLX_KEY_ENTER)
		data->key_action = false;
}

void	start_mlx(t_data *data)
{
	data->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D", FALSE);
	if (!data->mlx)
		system_error("MLX ERROR");
	data->image.map_img = mlx_new_image(data->mlx, MINIMAP_WIDTH, MINIMAP_WIDTH);
	data->image._3d = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->image.background = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);

	// Circle bres for player size on data->image.map_img
	//circleBres(PL_HITBOX, PL_HITBOX, PL_HITBOX, 0xFF0000FF, data->image.);

	ft_rectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT / 2, data->ceiling_color, data->image.background);
	ft_rectangle(0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT, data->floor_color, data->image.background);

	mlx_image_to_window(data->mlx, data->image.background, 0, 0);
	mlx_image_to_window(data->mlx, data->image._3d, 0, 0);
	mlx_image_to_window(data->mlx, data->image.map_img,
		WINDOW_WIDTH - MINIMAP_WIDTH, WINDOW_HEIGHT - MINIMAP_WIDTH);

	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(data->mlx, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	mlx_key_hook(data->mlx, key_action, data);
	mlx_cursor_hook(data->mlx, look_mouse, data);

	mlx_loop_hook(data->mlx, &update, data);
	mlx_loop(data->mlx);
}

int32_t	main(int argc, char **argv)
{
	t_data		*data;
	if (argc != 2)
	{
		ft_printf_error("ERROR: Wrong argument count\n");
		exit(11);
	}
	data = init_data(argv[1]);
	start_mlx(data);
	mlx_terminate(data->mlx);
	free_data(data);
	return (EXIT_SUCCESS);
}