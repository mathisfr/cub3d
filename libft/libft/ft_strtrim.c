/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <lloison@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:01:26 by lloison           #+#    #+#             */
/*   Updated: 2022/12/19 13:43:42 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	is_in_set(char c, char const *set, size_t set_size)
{
	size_t	i;

	i = 0;
	if (set == 0)
		return (0);
	while (i < set_size)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_start_index(char const *s1, char const *set,
	size_t set_size)
{
	size_t	i;

	i = 0;
	while (is_in_set(s1[i], set, set_size))
		i++;
	return (i);
}

static size_t	get_end_index(char const *s1, char const *set, size_t set_size)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (is_in_set(s1[i], set, set_size))
	{
		i--;
		if (i == 0)
			break ;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	set_size;
	size_t	start_index;
	size_t	end_index;

	if (s1 == 0)
		return (0);
	set_size = ft_strlen(set);
	start_index = get_start_index(s1, set, set_size);
	end_index = get_end_index(s1, set, set_size);
	if (start_index > end_index)
		return (ft_calloc(1, 1));
	return (ft_substr(s1, start_index, end_index - start_index + 1));
}
