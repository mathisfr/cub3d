/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:39:41 by lloison           #+#    #+#             */
/*   Updated: 2022/11/02 14:46:38 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*generate_output(unsigned int start, size_t size, size_t *len)
{
	char	*output;

	if (start > size)
	{
		output = (char *) malloc(1 * sizeof(char));
		*len = 0;
	}
	else if (start + *len > size)
	{
		output = (char *) malloc((size - start + 1) * sizeof(char));
		*len = size - start;
	}
	else
		output = (char *) malloc((*len + 1) * sizeof(char));
	return (output);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*output;
	unsigned int	i;
	size_t			size;

	if (s == 0)
		return (0);
	i = -1;
	size = ft_strlen(s);
	output = generate_output(start, size, &len);
	if (output == 0)
		return (0);
	while (++i < len && i < size)
		output[i] = s[start++];
	output[i] = '\0';
	return (output);
}
