// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "cub3d.h"

void	handle_collisions(t_data *data);

static mlx_image_t* img;
static mlx_image_t* player;

void hook(void* param)
{
	t_data* data = param;

	data->player->movement.x = 0;
	data->player->movement.y = 0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->player->movement.y -= 1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->player->movement.y += 1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->player->movement.x -= 1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->player->movement.x += 1;
	update_player(data->player,
		pos(player->instances[0].x, player->instances[0].y), data->map);
	player->instances[0].x += data->player->movement.x * PLAYER_SPEED;
	player->instances[0].y += data->player->movement.y * PLAYER_SPEED;
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
	mlx_loop_hook(mlx, &hook, data);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
