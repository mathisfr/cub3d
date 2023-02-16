/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:11:57 by lloison           #+#    #+#             */
/*   Updated: 2022/11/01 11:27:36 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	length;

	i = 0;
	j = 0;
	if (dstsize == 0 || ft_strlen(dst) >= dstsize)
		return (ft_strlen(src) + dstsize);
	else
		length = ft_strlen(dst) + ft_strlen(src);
	while (dst[i] != 0)
		i++;
	while (src[j] != 0 && i < dstsize - 1)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = 0;
	return (length);
}
