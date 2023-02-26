/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fc_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:52:00 by lloison           #+#    #+#             */
/*   Updated: 2023/02/25 14:32:24 by matfranc         ###   ########.fr       */
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

static void	check_if_valid_line2(char *line, int i, int j)
{
	while (j < 3)
	{
		while (is_space(line[i]))
			i++;
		if (!ft_isdigit(line[i]))
			parsing_error("Wrong format in ceiling/floor color");
		while (ft_isdigit(line[i]))
			i++;
		while (is_space(line[i]))
			i++;
		if (j != 2 && line[i] != ',')
			parsing_error("Wrong format in ceiling/floor color");
		if (j < 2 && line[i] == ',')
			i++;
		j++;
	}
	while (is_space(line[i]))
		i++;
	if (line[i])
		parsing_error("Too many information in ceiling/floor line");
}

static void	check_if_valid_line(t_data *data, char *line)
{
	int	i;
	int	j;

	i = 1;
	if ((line[0] == 'C' && data->ceiling_color != 0)
		|| (line[0] == 'F' && data->floor_color != 0))
		parsing_error("Multiple ceiling/floor color in file");
	if (!is_space(line[i]))
		parsing_error("Wrong format in ceiling/floor color");
	j = 0;
	check_if_valid_line2(line, i, j);
}

static void	skip_number(char *line, int *i)
{
	while (is_space(line[*i]))
		(*i)++;
	while (ft_isdigit(line[*i]))
		(*i)++;
	(*i)++;
}

int	parse_fc_color(t_data *data, char *line)
{
	int	i;
	int	r;
	int	g;
	int	b;

	check_if_valid_line(data, line);
	i = 1;
	r = ft_atoi(&(line[i]));
	if (r < 0 || r > 255)
		parsing_error("Invalid number for red color");
	skip_number(line, &i);
	g = ft_atoi(&(line[i]));
	if (g < 0 || g > 255)
		parsing_error("Invalid number for green color");
	skip_number(line, &i);
	b = ft_atoi(&(line[i]));
	if (b < 0 || b > 255)
		parsing_error("Invalid number for blue color");
	skip_number(line, &i);
	if (line[0] == 'C')
		data->ceiling_color = r | g << 8 | b << 16 | 0xFF << 24;
	else
		data->floor_color = r | g << 8 | b << 16 | 0xFF << 24;
	return (1);
}
