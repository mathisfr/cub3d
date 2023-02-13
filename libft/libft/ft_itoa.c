/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:22:57 by lloison           #+#    #+#             */
/*   Updated: 2022/11/01 15:06:03 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(int n)
{
	int	count;

	count = 1;
	if (n < 0)
		count++;
	while (n / 10 != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*get_string(int length, long long n2, int is_n)
{
	char	*output;

	output = (char *) malloc(sizeof(char) * (length + 1));
	if (output == 0)
		return (0);
	output[length] = 0;
	while (n2 / 10 > 0)
	{
		output[length - 1] = n2 % 10 + '0';
		length--;
		n2 /= 10;
	}
	output[length - 1] = n2 % 10 + '0';
	if (is_n == 1)
		output[0] = '-';
	return (output);
}

char	*ft_itoa(int n)
{
	int			is_n;
	int			length;
	long long	n2;

	is_n = 0;
	length = get_length(n);
	n2 = n;
	if (n2 < 0)
	{
		n2 *= -1;
		is_n = 1;
	}
	return (get_string(length, n2, is_n));
}
