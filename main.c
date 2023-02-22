/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:59:09 by lloison           #+#    #+#             */
/*   Updated: 2023/02/22 12:14:35 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "cub3d.h"

void	start_mlx(t_data *data)
{
	data->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D", FALSE);
	if (!data->mlx)
		system_error("MLX ERROR");
	data->image.map_img = mlx_new_image(data->mlx, WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
	data->image.player = mlx_new_image(data->mlx, (PL_HITBOX * 2) + 1, (PL_HITBOX * 2) + 1);
	data->image._3d = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->image.background = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->image.line = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);

	//Peut etre a degager
	data->player->dir.x = 0;
	data->player->dir.y = -(VEC_LEN / 2);
	//-

	//pour l'instant un cercle
	circleBres(PL_HITBOX, PL_HITBOX, PL_HITBOX, 0xFF0000FF, data->image.player);

	//draw minimap
	ft_draw_map(data->map, 0xFF00FF00, data->image.map_img);

	ft_rectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT / 2, data->ceiling_color, data->image.background);
	ft_rectangle(0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT, data->floor_color, data->image.background);

	mlx_image_to_window(data->mlx, data->image.background, 0, 0);
	mlx_image_to_window(data->mlx, data->image._3d, 0, 0);
	mlx_image_to_window(data->mlx, data->image.map_img, 0, 0);
	mlx_image_to_window(data->mlx, data->image.line, 0, 0);
	mlx_image_to_window(data->mlx, data->image.player, WALL_SIZE * data->player->tile_pos.x, WALL_SIZE * data->player->tile_pos.y);

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
