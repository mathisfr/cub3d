/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sstring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:26:12 by lloison           #+#    #+#             */
/*   Updated: 2022/11/06 14:32:58 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_sstring	*init_sstring(void)
{
	t_sstring	*output;

	output = (t_sstring *)malloc(sizeof(t_sstring));
	if (output == 0)
		return (0);
	output->text = (char *)malloc(sizeof(char));
	if (output->text == 0)
	{
		free(output);
		return (0);
	}
	output->text[0] = 0;
	output->length = 0;
	return (output);
}

void	*free_sstring(t_sstring **string)
{
	if (*string)
	{
		if ((*string)->text)
			free((*string)->text);
		free(*string);
	}
	return (0);
}

static void	add_to_text_helper(char *output, t_sstring **string,
	char *to_add, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < (*string)->length)
	{
		output[i] = (*string)->text[i];
		i++;
	}
	j = 0;
	while (j < size)
	{
		output[i] = to_add[j];
		i++;
		j++;
	}
	output[i] = 0;
}

int	add_to_text(t_sstring **string, char *to_add, size_t size)
{
	char	*output;

	output = (char *) malloc(sizeof(char) * ((*string)->length + size + 1));
	if (output == 0)
	{
		free(to_add);
		return (-1);
	}
	add_to_text_helper(output, string, to_add, size);
	(*string)->length += size;
	free((*string)->text);
	free(to_add);
	(*string)->text = output;
	return (0);
}
