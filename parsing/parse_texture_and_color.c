/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_and_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:20:59 by lloison           #+#    #+#             */
/*   Updated: 2023/02/23 17:23:11 by lloison          ###   ########.fr       */
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

static int	check_line(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (line[i] && is_space(line[i]))
			i++;
		if (!line[i])
			break;
		if (line[i] == 'C' || line[i] == 'F')
			return (parse_fc_color(data, &(line[i])));
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'E')
			return (parse_texture(data, &(line[i])));
		else
			parsing_error("Invalid character in map");
	}
	return (0);
}

void	parse_texture_and_color(t_data *data, int fd)
{
	char	*tmp_line;
	int		nb_data_parsed;

	nb_data_parsed = 0;
	tmp_line = get_next_line(fd);
	while (tmp_line && nb_data_parsed < 6)
	{
		nb_data_parsed += check_line(data, tmp_line);
		free(tmp_line);
		if (nb_data_parsed < 6)
			tmp_line = get_next_line(fd);
	}
	if (nb_data_parsed != 6)
		parsing_error("Failed to initialize all value from the input file");
}