/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:51:18 by lloison           #+#    #+#             */
/*   Updated: 2023/02/22 12:12:29 by lloison          ###   ########.fr       */
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
