/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:41:29 by lloison           #+#    #+#             */
/*   Updated: 2022/11/01 10:34:55 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*output;
	size_t	i;
	size_t	total_size;

	total_size = count * size;
	i = 0;
	output = (char *)malloc(total_size);
	if (output == 0)
		return (0);
	while (i < total_size)
	{
		output[i] = 0;
		i++;
	}
	return (output);
}
