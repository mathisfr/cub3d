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
	t_vector u;
	u.x = 0;
	u.y = -1;
	ft_vector_rotation(&u, (float)data->player->angle);
	ft_memset(data->line->pixels, 1, data->line->width * data->line->height * sizeof(int32_t));
<<<<<<< HEAD

=======
>>>>>>> e5cbb42172281f9175272ee3bd5da4fac6e4c4a3
	float angle = -(PLAYER_FOV / 2.0);
	ft_memset(data->_3d->pixels, 1, data->_3d->width * data->_3d->height * sizeof(int32_t));
	for(int i = 0; i < (int)data->_3d->width; i += DOWN_SCALE)
	{
		v.x = u.x;
		v.y = u.y;
		angle += (PLAYER_FOV / 2.0) / (data->_3d->width / (2 * DOWN_SCALE));
		ft_vector_rotation(&v, angle);
		draw_ray(data, data->map, data->player->map_pos, data->player->tile_pos, v, i);
	}
<<<<<<< HEAD
}

/*
 * Returns the current, relative, mouse cursor position on the window, starting
 * from the top left corner.
 *
 * Negative values or values greater than window width or height
 * indicate that it is outside the window.
 *
 * @param[in] mlx The MLX instance handle.
 * @param[out] x The position.
 * @param[out] y The position.

void mlx_get_mouse_pos(mlx_t* mlx, int32_t* x, int32_t* y);


 * Sets the mouse position.
 *
 * @param[in] mlx The MLX instance handle.
 * @param[in] pos The position.

void mlx_set_mouse_pos(mlx_t* mlx, int32_t x, int32_t y);


 * This function sets the cursor callback, which is called when the
 * mouse position changes. Position is relative to the window.
 *
 * @param[in] mlx The MLX instance handle.
 * @param[in] func The cursor callback function.
 * @param[in] param An additional optional parameter.

void mlx_cursor_hook(mlx_t* mlx, mlx_cursorfunc func, void* param);


 * Callback function used to handle raw mouse movement.
 *
 * @param[in] xpos The mouse x position.
 * @param[in] ypos The mouse y position.
 * @param[in] param Additional parameter to pass on to the function.

typedef void (*mlx_cursorfunc)(double xpos, double ypos, void* param);
*/

void	look_mouse(double xpos, double ypos, void *param)
{
	t_data	*data;

	(void) ypos;
	data = (t_data *)param;
	if (xpos > 0 && xpos < WINDOW_WIDTH && xpos != WINDOW_WIDTH / 2)
	{
		if (xpos > WINDOW_WIDTH / 2)
			data->player->angle += round((xpos - (WINDOW_WIDTH / 2)) * SENSITIVITY);
		else if (xpos < WINDOW_WIDTH / 2)
			data->player->angle -= round(((WINDOW_WIDTH / 2) - xpos) * SENSITIVITY);
		mlx_set_mouse_pos(data->mlx, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	}

}

void	key_action(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.action == MLX_PRESS
		&& keydata.key == MLX_KEY_ENTER)
		data->key_action = true;
	if (keydata.action == MLX_RELEASE
		&& keydata.key == MLX_KEY_ENTER)
		data->key_action = false;
=======
>>>>>>> e5cbb42172281f9175272ee3bd5da4fac6e4c4a3
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
	data->texture.wall_n = mlx_load_png("/Users/matfranc/Downloads/brick.png");
	map_img = mlx_new_image(mlx, WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
	vector_dir = mlx_new_image(mlx, VEC_LEN, VEC_LEN);
	player = mlx_new_image(mlx, (PL_HITBOX * 2) + 1, (PL_HITBOX * 2) + 1);
	data->_3d = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->background = mlx_new_image(mlx, data->_3d->width, data->_3d->height);
	data->img = player;
	data->vec_dir = vector_dir;
	data->key_action = FALSE;
	if (data->player->tile_pos.y == 0)
		data->player->tile_pos.y = 1;
	if (data->player->tile_pos.x == 0)
		data->player->tile_pos.x = 1;
	data->player->dir.x = 0;
	data->player->dir.y = -(VEC_LEN / 2);
	circleBres(PL_HITBOX, PL_HITBOX, PL_HITBOX, 0xFF0000FF, player);
	ft_draw_map(data->map, 0xFF00FF00, map_img);
	ft_line(data->vec_dir, VEC_LEN / 2, VEC_LEN / 2, VEC_LEN / 2 + data->player->dir.x, VEC_LEN / 2 + data->player->dir.y, 0xFF0000FF);
	ft_rectangle(0, 0, data->_3d->width, data->_3d->height / 2, 0xFFFF0000, data->background);
	ft_rectangle(0, data->_3d->height / 2, data->_3d->width, data->_3d->height, 0xFF00FF00, data->background);
	mlx_image_to_window(mlx, data->background, 0, 0);
	mlx_image_to_window(mlx, data->_3d, 0, 0);
	mlx_image_to_window(mlx, map_img, 0, 0);
	mlx_image_to_window(mlx, player, WALL_SIZE * data->player->tile_pos.x, WALL_SIZE * data->player->tile_pos.y);
	mlx_image_to_window(mlx, vector_dir, WALL_SIZE * data->player->tile_pos.x, WALL_SIZE * data->player->tile_pos.y);
	mlx_image_t *line = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_image_to_window(mlx, line, 0, 0);
	data->line = line;
	data->line->instances[0].enabled = 0;
	map_img->instances[0].enabled = 0;
	data->img->instances[0].enabled = 0;
	data->vec_dir->instances[0].enabled = 0;
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(data->mlx, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	mlx_key_hook(mlx, key_action, data);
	mlx_loop_hook(mlx, &hook, data);
	mlx_cursor_hook(mlx, look_mouse, data);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
