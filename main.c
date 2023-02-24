/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:59:09 by lloison           #+#    #+#             */
/*   Updated: 2023/02/24 14:22:12 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "cub3d.h"

void	set_background(t_data *data)
{
	t_vector	start;
	t_vector	end;

	start.x = 0;
	start.y = 0;
	end.x = WINDOW_WIDTH;
	end.y = WINDOW_HEIGHT / 2;
	ft_rectangle(start, end,
		data->ceiling_color, data->image.background);
	start.y = WINDOW_HEIGHT / 2;
	end.y = WINDOW_HEIGHT;
	ft_rectangle(start, end,
		data->floor_color, data->image.background);
	mlx_image_to_window(data->mlx, data->image.background, 0, 0);
}

void	start_mlx(t_data *data)
{
	data->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D", FALSE);
	if (!data->mlx)
		system_error("MLX ERROR");
	data->image.map_img = mlx_new_image(data->mlx,
			MINIMAP_WIDTH, MINIMAP_WIDTH);
	data->image._3d = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->image.background = mlx_new_image(data->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	data->key_action = FALSE;
	data->anim_state = FALSE;
	data->texture.door = mlx_load_png("./textures/door.png");
	set_background(data);
	mlx_image_to_window(data->mlx, data->image._3d, 0, 0);
	mlx_image_to_window(data->mlx, data->image.map_img,
		WINDOW_WIDTH - MINIMAP_WIDTH, WINDOW_HEIGHT - MINIMAP_WIDTH);
	init_animation(data);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(data->mlx, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	mlx_key_hook(data->mlx, key_action, data);
	mlx_mouse_hook(data->mlx, mouse_action, data);
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
	free_data(data);
	return (EXIT_SUCCESS);
}
