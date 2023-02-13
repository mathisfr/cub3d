/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:41:58 by lloison           #+#    #+#             */
/*   Updated: 2022/11/07 10:42:09 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	normal_behavior(t_sstring **string,	char *s, char *spaces)
{
	if (add_to_text(string, spaces, ft_strlen(spaces)) == -1)
	{
		free(s);
		return (-1);
	}
	return (add_to_text(string, s, ft_strlen(s)));
}

int	minus_behavior(t_sstring **string, char *s, char *spaces)
{
	if (add_to_text(string, s, ft_strlen(s)) == -1)
	{
		free(spaces);
		return (-1);
	}
	return (add_to_text(string, spaces, ft_strlen(spaces)));
}
