/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:51:18 by lloison           #+#    #+#             */
/*   Updated: 2023/02/16 17:51:55 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
t_data	*init_data(mlx_t *mlx, char *filename)
{
	t_data	*output;

	output = ft_calloc(sizeof(t_data), 1);
	if (!output)
		malloc_error();
	output->mlx = mlx;
	output->map = parse_map(filename);
	output->player = init_player(output->map);
	return (output);
}
