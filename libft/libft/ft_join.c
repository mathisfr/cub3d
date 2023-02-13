/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:56:28 by lloison           #+#    #+#             */
/*   Updated: 2023/01/25 15:43:11 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(char **s)
{
	int	length;
	int	i;

	i = 0;
	length = 0;
	while (s[i])
	{
		length += ft_strlen(s[i]) + 1;
		i++;
	}
	return (length - 1);
}

static void	copy_to_output(char **splitted_s, char *output, char c)
{
	int	i;
	int	j;
	int	output_i;

	i = 0;
	output_i = 0;
	while (splitted_s[i])
	{
		j = 0;
		while (splitted_s[i][j])
		{
			output[output_i] = splitted_s[i][j];
			j++;
			output_i++;
		}
		i++;
		if (splitted_s[i])
		{
			output[output_i] = c;
			output_i++;
		}
	}
}

char	*ft_join(char **splitted_s, char c)
{
	char	*output;
	int		length;

	length = get_length(splitted_s);
	output = malloc(sizeof(char) * (length + 1));
	if (!output)
		return (0);
	output[length] = 0;
	copy_to_output(splitted_s, output, c);
	return (output);
}
