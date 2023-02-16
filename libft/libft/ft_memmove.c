/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:28:42 by lloison           #+#    #+#             */
/*   Updated: 2022/10/31 17:06:22 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*dest;
	char	*source;

	dest = (char *) dst;
	source = (char *) src;
	if (source < dest && source + len > dest)
	{
		i = len - 1;
		while (i >= 0)
		{
			dest[i] = source[i];
			i--;
		}
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, len));
}
