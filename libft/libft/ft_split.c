/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:56:08 by lloison           #+#    #+#             */
/*   Updated: 2022/11/07 15:36:16 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_nb_words(char const *s, char c)
{
	size_t	i;
	size_t	nb_words;
	int		counting;

	i = 0;
	counting = 0;
	nb_words = 0;
	while (s[i])
	{
		if (s[i] == c && counting == 1)
		{
			nb_words++;
			counting = 0;
		}
		else if (s[i] != c && counting == 0)
			counting = 1;
		i++;
	}
	return (nb_words + counting);
}

static char	*ft_strncpy(char *dest, char const *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

static char	*get_next_word(char const *s, char c, size_t *index)
{
	char	*output;
	size_t	length;
	size_t	start_index;

	length = 0;
	while (s[*index] == c)
		*index = *index + 1;
	start_index = *index;
	while (s[*index] && s[*index] != c)
	{
		length++;
		*index = *index + 1;
	}
	output = (char *) malloc(sizeof(char) * (length + 1));
	if (output == 0)
		return (0);
	ft_strncpy(output, &s[start_index], length);
	output[length] = '\0';
	return (output);
}

static void	free_if_error(char **output, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(output[i]);
		i++;
	}
	free(output);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	nb_words;
	size_t	s_index;
	char	**output;

	i = 0;
	if (s == 0)
		return (0);
	nb_words = count_nb_words(s, c);
	s_index = 0;
	output = (char **) malloc(sizeof(char *) * (nb_words + 1));
	if (output == 0)
		return (0);
	while (i < nb_words)
	{
		output[i] = get_next_word(s, c, &s_index);
		if (output[i] == 0)
		{
			free_if_error(output, i);
			return (0);
		}
		i++;
	}
	output[i] = 0;
	return (output);
}
