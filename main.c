/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:59:09 by lloison           #+#    #+#             */
/*   Updated: 2023/02/23 18:33:35 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "cub3d.h"

void	look_mouse(double xpos, double ypos, void *param)
{
	t_data	*data;

	(void) ypos;
	data = (t_data *)param;
	if (xpos > 0 && xpos < WINDOW_WIDTH && xpos != WINDOW_WIDTH / 2)
	{
		if (xpos > WINDOW_WIDTH / 2)
			data->player->angle += ((xpos - (WINDOW_WIDTH / 2))
					* SENSITIVITY * data->delta_time * 20.0);
		else if (xpos < WINDOW_WIDTH / 2)
			data->player->angle -= (((WINDOW_WIDTH / 2) - xpos)
					* SENSITIVITY * data->delta_time * 20.0);
		mlx_set_mouse_pos(data->mlx, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	}
}

void	doors_manager(char door, char state, t_data *data)
{
	int	posy;
	int	posx;

	posy = data->player->tile_pos.y;
	posx = data->player->tile_pos.x;
	if (data->player->angle > 315 || data->player->angle < 45)
	{
		if (data->map->map_arr[posy - 1][posx] == door)
			data->map->map_arr[posy - 1][posx] = state;
		else if (data->map->map_arr[posy - 1][posx] == state)
			data->map->map_arr[posy - 1][posx] = door;
	}
	if (data->player->angle > 45 && data->player->angle < 135)
	{
		if (data->map->map_arr[posy][posx + 1] == door)
			data->map->map_arr[posy][posx + 1] = state;
		else if (data->map->map_arr[posy][posx + 1] == state)
			data->map->map_arr[posy][posx + 1] = door;
	}
	if (data->player->angle > 135 && data->player->angle < 225)
	{
		if (data->map->map_arr[posy + 1][posx] == door)
			data->map->map_arr[posy + 1][posx] = state;
		else if (data->map->map_arr[posy + 1][posx] == state)
			data->map->map_arr[posy + 1][posx] = door;
	}
	if (data->player->angle > 225 && data->player->angle < 315)
	{
		if (data->map->map_arr[posy][posx - 1] == door)
			data->map->map_arr[posy][posx - 1] = state;
		else if (data->map->map_arr[posy][posx - 1] == state)
			data->map->map_arr[posy][posx - 1] = door;
	}
}

void	key_action(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.action == MLX_PRESS
		&& (keydata.key == MLX_KEY_SPACE))
		doors_manager('2', '3', data);
	else if (keydata.action == MLX_PRESS
		&& keydata.key == MLX_KEY_LEFT_SHIFT)
		data->key_action = TRUE;
	else if (keydata.action == MLX_RELEASE
		&& keydata.key == MLX_KEY_LEFT_SHIFT)
		data->key_action = FALSE;
}

void	mouse_action(mouse_key_t button, action_t action,
	modifier_key_t mods, void *param)
{
	t_data	*data;

	(void) mods;
	data = (t_data *)param;
	if (button == MLX_MOUSE_BUTTON_LEFT
		&& action == MLX_PRESS)
		data->key_action = TRUE;
	else if (button == MLX_MOUSE_BUTTON_LEFT
		&& action == MLX_RELEASE)
		data->key_action = FALSE;
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
	ft_rectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT / 2,
		data->ceiling_color, data->image.background);
	ft_rectangle(0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT,
		data->floor_color, data->image.background);
	mlx_image_to_window(data->mlx, data->image.background, 0, 0);
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
