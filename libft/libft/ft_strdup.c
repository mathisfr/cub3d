/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:50:43 by lloison           #+#    #+#             */
/*   Updated: 2023/01/17 12:25:50 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	size_t	i;
	char	*output;

	if (s1 == 0)
		return (0);
	size = ft_strlen(s1);
	i = 0;
	output = (char *) malloc((size + 1) * sizeof(char));
	if (output == 0)
		return (0);
	while (i < size)
	{
		output[i] = s1[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*ft_strndup(const char *s1, int n)
{
	size_t	size;
	size_t	i;
	char	*output;

	if (s1 == 0)
		return (0);
	size = ft_strlen(s1);
	if (size > (size_t)n)
		size = n;
	i = 0;
	output = (char *) malloc((size + 1) * sizeof(char));
	if (output == 0)
		return (0);
	while (i < size)
	{
		output[i] = s1[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
