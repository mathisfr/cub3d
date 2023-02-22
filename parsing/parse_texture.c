/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:23:54 by lloison           #+#    #+#             */
/*   Updated: 2023/02/21 16:46:04 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	is_space(char c)
{
	if (c != '\t' && c != '\n' && c != '\v' && c != '\f'
		&& c != '\r' && c != ' ')
		return (FALSE);
	return (TRUE);
}

static void	check_if_rewrite(t_data *data, char *line)
{
	if ((ft_strncmp(line, "NO", 2) == 0 && data->texture.wall_n)
		|| (ft_strncmp(line, "SO", 2) == 0 && data->texture.wall_s)
		|| (ft_strncmp(line, "WE", 2) == 0 && data->texture.wall_o)
		|| (ft_strncmp(line, "EA", 2) == 0 && data->texture.wall_e))
		parsing_error("Multiple texture for the same wall in input file");
}

static void	check_line(char *line)
{
	int	i;

	i = 2;
	if (ft_strncmp(line, "NO", 2) == 0
		|| ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0
		|| ft_strncmp(line, "EA", 2) == 0)
	{
		if (!is_space(line[2]))
			parsing_error("Wrong format in input file");
		while (is_space(line[i]))
			i++;
		while (!is_space(line[i]))
			i++;
		while(is_space(line[i]))
			i++;
		if (line[i])
			parsing_error("Wrong format in input file");
		return ;
	}
	parsing_error("Wrong format in input file");
}

static mlx_texture_t	*load_texture(char *line)
{
	int				i;
	char			*file_path;
	mlx_texture_t	*output;

	i = 2;
	while (is_space(line[i]))
		i++;
	file_path = ft_strtrim(&(line[i]), "\t\n\v\f\r ");
	if (!file_path)
		malloc_error();
	output = mlx_load_png(file_path);
	if (!output)
		system_error("Failed to load texture:");
	free(file_path);
	return (output);
}

int	parse_texture(t_data *data, char *line)
{
	mlx_texture_t	*texture;

	check_line(line);
	check_if_rewrite(data, line);
	texture = load_texture(line);
	if (line[0] == 'N')
		data->texture.wall_n = texture;
	else if (line[0] == 'S')
		data->texture.wall_s = texture;
	else if (line[0] == 'W')
		data->texture.wall_o = texture;
	else if (line[0] == 'E')
		data->texture.wall_e = texture;
	return (1);
}