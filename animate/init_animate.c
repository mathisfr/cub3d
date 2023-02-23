/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:17:12 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/23 16:13:04 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_animation(t_data *data)
{
	int	i;
	int	posx;
	int	posy;

	i = 1;
	posx = (WINDOW_WIDTH / 2) - (data->anim.img[0]->width / 2);
	posy = (WINDOW_HEIGHT) - (data->anim.img[0]->height);
	while (i < 10)
	{
		mlx_image_to_window(data->mlx, data->anim.img[i], posx, posy);
		data->anim.img[i]->enabled = FALSE;
		i++;
	}
	mlx_image_to_window(data->mlx, data->anim.img[0], posx, posy);
}

void	init_animation(t_data *data)
{
	data->anim.tex[0] = mlx_load_png("./textures/animate/doom_0.png");
	data->anim.tex[1] = mlx_load_png("./textures/animate/doom_1.png");
	data->anim.tex[2] = mlx_load_png("./textures/animate/doom_2.png");
	data->anim.tex[3] = mlx_load_png("./textures/animate/doom_3.png");
	data->anim.tex[4] = mlx_load_png("./textures/animate/doom_4.png");
	data->anim.tex[5] = mlx_load_png("./textures/animate/doom_5.png");
	data->anim.tex[6] = mlx_load_png("./textures/animate/doom_6.png");
	data->anim.tex[7] = mlx_load_png("./textures/animate/doom_7.png");
	data->anim.tex[8] = mlx_load_png("./textures/animate/doom_8.png");
	data->anim.tex[9] = mlx_load_png("./textures/animate/doom_9.png");
	data->anim.img[0] = mlx_texture_to_image(data->mlx, data->anim.tex[0]);
	data->anim.img[1] = mlx_texture_to_image(data->mlx, data->anim.tex[1]);
	data->anim.img[2] = mlx_texture_to_image(data->mlx, data->anim.tex[2]);
	data->anim.img[3] = mlx_texture_to_image(data->mlx, data->anim.tex[3]);
	data->anim.img[4] = mlx_texture_to_image(data->mlx, data->anim.tex[4]);
	data->anim.img[5] = mlx_texture_to_image(data->mlx, data->anim.tex[5]);
	data->anim.img[6] = mlx_texture_to_image(data->mlx, data->anim.tex[6]);
	data->anim.img[7] = mlx_texture_to_image(data->mlx, data->anim.tex[7]);
	data->anim.img[8] = mlx_texture_to_image(data->mlx, data->anim.tex[8]);
	data->anim.img[9] = mlx_texture_to_image(data->mlx, data->anim.tex[9]);
	load_animation(data);
}
