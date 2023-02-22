/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fc_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:52:00 by lloison           #+#    #+#             */
/*   Updated: 2023/02/21 16:57:43 by lloison          ###   ########.fr       */
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
		i++;
		j++;
	}
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
	printf("status before : %s\n", &(line[i]));
	r = ft_atoi(&(line[i]));
	if (r < 0 || r > 255)
		parsing_error("Invalid number for red color");
	skip_number(line, &i);
	printf("status after : %s\n", &(line[i]));
	g = ft_atoi(&(line[i]));
	if (g < 0 || g > 255)
		parsing_error("Invalid number for green color");
	skip_number(line, &i);
	b = ft_atoi(&(line[i]));
	if (b < 0 || b > 255)
		parsing_error("Invalid number for blue color");
	skip_number(line, &i);
	printf("r : %d\tg : %d\tb : %d\n", r, g, b);
	if (line[0] == 'C')
		data->ceiling_color = r | g << 8 | b << 16 | 0xFF << 24;
	else
		data->floor_color = r | g << 8 | b << 16 | 0xFF << 24;
	return (1);
}