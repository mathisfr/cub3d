/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:51:18 by lloison           #+#    #+#             */
/*   Updated: 2023/02/24 14:21:56 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	open_file(char *filepath)
{
	int	fd;

	check_extension(filepath);
	fd = open(filepath, O_RDONLY);
	if (fd == -1 || fd == 0)
		system_error("PARSING: can't open input file");
	return (fd);
}

void	free_structs(mlx_t *mlx, t_animate *anim, t_image *img, t_texture *tex)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		mlx_delete_image(mlx, anim->img[i]);
		mlx_delete_texture(anim->tex[i]);
		i++;
	}
	mlx_delete_image(mlx, img->background);
	mlx_delete_image(mlx, img->map_img);
	mlx_delete_image(mlx, img->_3d);
	mlx_delete_texture(tex->wall_e);
	mlx_delete_texture(tex->wall_n);
	mlx_delete_texture(tex->wall_o);
	mlx_delete_texture(tex->wall_s);
	mlx_delete_texture(tex->door);
}

//Free data (must be updated with all mlx image maybe ?)
void	free_data(t_data *data)
{
	int	i;

	if (!data)
		return ;
	i = -1;
	while (++i < data->map->max_y_size)
		free(data->map->map_arr[i]);
	free(data->map->map_arr);
	free(data->map);
	ft_lstclear(&(data->player->collider.all_tiles), free);
	free_structs(data->mlx, &(data->anim), &(data->image), &(data->texture));
	free(data->player);
	mlx_terminate(data->mlx);
	free(data);
}

//Init data with starting value (call parser)
t_data	*init_data(char *filename)
{
	int		fd;
	t_data	*output;

	fd = open_file(filename);
	output = ft_calloc(sizeof(t_data), 1);
	if (!output)
		malloc_error();
	parse_texture_and_color(output, fd);
	output->map = parse_map(fd);
	close(fd);
	output->player = init_player(output->map);
	return (output);
}
