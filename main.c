// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "cub3d.h"

static mlx_image_t* img;
static mlx_image_t* player;

void hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		player->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		player->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		player->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		player->instances[0].x += 5;
}

int32_t	main(int argc, char **argv)
{
	mlx_t	*mlx;
	t_data	*data;

	if (argc != 2)
	{
		ft_printf_error("ERROR: Wrong argument count\n");
		exit(11);
	}
	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D", FALSE);
	if (!mlx)
		system_error("MLX ERROR");
	data = init_data(mlx, argv[1]);
	img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	player = mlx_new_image(mlx, WALL_SIZE + 1, WALL_SIZE + 1);
	if (data->player->tile_pos.y == 0)
		data->player->tile_pos.y = 1;
	if (data->player->tile_pos.x == 0)
		data->player->tile_pos.x = 1;
	circleBres((WALL_SIZE / 2), (WALL_SIZE / 2), WALL_SIZE / 2, 0xFF0000FF, player);
	ft_draw_map(data->map, 0xFF00FF00, img);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_image_to_window(mlx, player, WALL_SIZE * data->player->tile_pos.x, WALL_SIZE * data->player->tile_pos.y);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
