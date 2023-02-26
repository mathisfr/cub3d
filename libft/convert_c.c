/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:40:02 by lloison           #+#    #+#             */
/*   Updated: 2022/11/18 12:03:48 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	are_flags_valid(t_flags *flags)
{
	if (flags->plus == 1 || flags->hashtag == 1
		|| flags->blank == 1 || flags->zero == 1)
		return (-1);
	return (0);
}

static int	minus_behavior2(t_flags *flags, t_sstring **string, char *to_add)
{
	char	*tmp;

	if (add_to_text(string, to_add, 1) == -1)
		return (-1);
	tmp = gen_array(' ', flags->precision_x - 1);
	if (tmp == 0)
		return (-1);
	return (add_to_text(string, tmp, flags->precision_x - 1));
}

static int	normal_behavior2(t_flags *flags, t_sstring **string, char *to_add)
{
	char	*tmp;

	tmp = gen_array(' ', flags->precision_x - 1);
	if (tmp == 0)
	{
		free(to_add);
		return (-1);
	}
	if (add_to_text(string, tmp, flags->precision_x - 1) == -1)
	{
		free(to_add);
		return (-1);
	}
	return (add_to_text(string, to_add, 1));
}

int	convert_c(t_flags *flags, va_list args, t_sstring **string)
{
	char	tmp[2];
	char	*to_add;

	if (are_flags_valid(flags) == -1)
		return (-1);
	tmp[0] = (char)va_arg(args, int);
	tmp[1] = 0;
	to_add = ft_strdup(tmp);
	if (to_add == 0)
		return (-1);
	if (flags->precision_x > 1)
	{
		if (flags->minus == 1)
			return (minus_behavior2(flags, string, to_add));
		else
			return (normal_behavior2(flags, string, to_add));
	}
	return (add_to_text(string, to_add, 1));
}
