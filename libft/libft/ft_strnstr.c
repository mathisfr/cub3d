/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:22:14 by lloison           #+#    #+#             */
/*   Updated: 2022/11/02 14:18:31 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_complete_occurence(const char *str, const char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i] != '\0')
	{
		if (str[i] != to_find[i])
			return (0);
		i++;
	}
	if (to_find[i] == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_size;

	i = 0;
	if (needle[0] == 0)
		return ((char *) haystack);
	if (len == 0)
		return (0);
	needle_size = ft_strlen(needle);
	while (haystack[i] && i + needle_size <= len)
	{
		if (haystack[i] == needle[0])
			if (is_complete_occurence(&haystack[i], needle) == 1)
				return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
