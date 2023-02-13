/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_template.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:06:19 by lloison           #+#    #+#             */
/*   Updated: 2023/02/13 16:19:11 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	mlx_t	*mlx;

	if (argc != 2)
	{
		ft_printf_error("ERROR: Wrong argument count\n");
		exit(11);
	}
	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D", FALSE);
	if (!mlx)
		system_error("MLX ERROR");
	data = init_data(mlx, argv[1]);
	//do all mlx stuff
	free_data(data);
	return (0);
}
