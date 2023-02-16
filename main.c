// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "cub3d.h"

void hook(void* param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	ft_movement(data);
	t_vector v;
	v.x = 0;
	v.y = -1;
	v = normalize_vector(v);
	ft_memset(data->line->pixels, 1, data->line->width * data->line->height * sizeof(int32_t));
	//for (int i = 315; i < 360; i++)
	//{
	//	v.x = 0;
	//	v.y = -1;
	//	ft_vector_rotation(&v, (float)data->player->angle);
	//	ft_vector_rotation(&v, (float)i);
	//	printf("i : %d\n", i);
	//	draw_ray(data, data->map, data->player->map_pos, data->player->tile_pos, v);
	//}
	//for(int i = 0; i <= 45; i++)
	//{
	//	v.x = 0;
	//	v.y = -1;
	//	v = normalize_vector(v);
	//	ft_vector_rotation(&v, (float)data->player->angle);
	//	ft_vector_rotation(&v, (float)i);
	//	draw_ray(data, data->map, data->player->map_pos, data->player->tile_pos, v);
	//}

	float angle = -30;
	ft_memset(data->_3d->pixels, 1, data->_3d->width * data->_3d->height * sizeof(int32_t));
	for(int i = 0; i < WINDOW_WIDTH; i++)
	{
		v.x = 0;
		v.y = -1;
		ft_vector_rotation(&v, (float)data->player->angle);
		angle += 30.0 / (WINDOW_WIDTH/2);
		ft_vector_rotation(&v, angle);
		v = normalize_vector(v);
		draw_ray(data, data->map, data->player->map_pos, data->player->tile_pos, v, i);
	}

	// draw_ray(data, data->map, data->player->map_pos, data->player->tile_pos, v);
	// v.x = +1;
	// v.y = +1;
	// v = normalize_vector(v);
	// draw_ray(data, data->map, data->player->map_pos, data->player->tile_pos, v);
	// v.x = +1;
	// v.y = -1;
	// v = normalize_vector(v);
	// draw_ray(data, data->map, data->player->map_pos, data->player->tile_pos, v);
	// v.x = -1;
	// v.y = 1;
	// v = normalize_vector(v);
	// draw_ray(data, data->map, data->player->map_pos, data->player->tile_pos, v);
	// v.y = 1;
	// v.x = 0;
	// v = normalize_vector(v);
	// draw_ray(data, data->map, data->player->map_pos, data->player->tile_pos, v);
	// v.y = -1;
	// v = normalize_vector(v);
	// draw_ray(data, data->map, data->player->map_pos, data->player->tile_pos, v);
	// v.y = 0;
	// v.x = 1;
	// v = normalize_vector(v);
	// draw_ray(data, data->map, data->player->map_pos, data->player->tile_pos, v);
	// v.x = -1;
	// v = normalize_vector(v);
	// draw_ray(data, data->map, data->player->map_pos, data->player->tile_pos, v);
}

int32_t	main(int argc, char **argv)
{
	mlx_t		*mlx;
	t_data		*data;
	mlx_image_t	*player;
	mlx_image_t	*vector_dir;
	mlx_image_t	*map_img;

	if (argc != 2)
	{
		ft_printf_error("ERROR: Wrong argument count\n");
		exit(11);
	}
	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D", FALSE);
	if (!mlx)
		system_error("MLX ERROR");
	data = init_data(mlx, argv[1]);
	map_img = mlx_new_image(mlx, WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
	vector_dir = mlx_new_image(mlx, VEC_LEN, VEC_LEN);
	player = mlx_new_image(mlx, (PL_HITBOX * 2) + 1, (PL_HITBOX * 2) + 1);
	data->_3d = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img = player;
	data->vec_dir = vector_dir;
	if (data->player->tile_pos.y == 0)
		data->player->tile_pos.y = 1;
	if (data->player->tile_pos.x == 0)
		data->player->tile_pos.x = 1;
	data->player->dir.x = 0;
	data->player->dir.y = -(VEC_LEN / 2);
	circleBres(PL_HITBOX, PL_HITBOX, PL_HITBOX, 0xFF0000FF, player);
	ft_draw_map(data->map, 0xFF00FF00, map_img);
	ft_line(data->vec_dir, VEC_LEN / 2, VEC_LEN / 2, VEC_LEN / 2 + data->player->dir.x, VEC_LEN / 2 + data->player->dir.y, 0xFF0000FF);
	mlx_image_to_window(mlx, map_img, 0, 0);
	mlx_image_to_window(mlx, data->_3d, 0, 0);
	mlx_image_to_window(mlx, player, WALL_SIZE * data->player->tile_pos.x, WALL_SIZE * data->player->tile_pos.y);
	mlx_image_to_window(mlx, vector_dir, WALL_SIZE * data->player->tile_pos.x, WALL_SIZE * data->player->tile_pos.y);
	mlx_image_t *line = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_image_to_window(mlx, line, 0, 0);
	data->line = line;
	mlx_loop_hook(mlx, &hook, data);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
