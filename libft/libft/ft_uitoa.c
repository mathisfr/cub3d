/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:22:57 by lloison           #+#    #+#             */
/*   Updated: 2022/11/04 19:06:01 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(unsigned int n)
{
	int	count;

	count = 1;
	while (n / 10 != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_uitoa(unsigned int n)
{
	char	*output;
	int		length;

	length = get_length(n);
	output = (char *) malloc(sizeof(char) * (length + 1));
	if (output == 0)
		return (0);
	output[length] = 0;
	while (n / 10 > 0)
	{
		output[length - 1] = n % 10 + '0';
		length--;
		n /= 10;
	}
	output[length - 1] = n % 10 + '0';
	return (output);
}
