/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:01:09 by lloison           #+#    #+#             */
/*   Updated: 2022/11/08 15:32:38 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	are_flags_valid(t_flags *flags)
{
	if (flags->hashtag == 1)
		return (-1);
	if (flags->precision == 0 && flags->zero == 1)
	{
		flags->precision_y = flags->precision_x;
		flags->precision_x = 0;
	}
	if (flags->plus == 1 && flags->blank == 1)
		flags->blank = 0;
	if (flags->precision == 1 && flags->zero == 1)
		flags->zero = 0;
	return (0);
}

static char	*generate_to_add(t_flags *flags, unsigned int arg)
{
	char	*output;
	int		is_n;

	is_n = 0;
	if (arg == 0 && flags->precision == 1 && flags->precision_y == 0)
	{
		output = gen_array(' ', flags->blank);
		output = add_plus(output, flags, arg, is_n);
		if (output == 0)
			return (0);
		return (output);
	}
	output = ft_uitoa(arg);
	output = add_zeros(output, flags, arg);
	output = add_blank(output, flags);
	if (is_n)
		output = add_minus(output, flags, is_n);
	output = add_plus(output, flags, arg, is_n);
	if (output == 0)
		return (0);
	return (output);
}

int	convert_u(t_flags *flags, va_list args, t_sstring **string)
{
	unsigned int	number;
	char			*to_add;
	char			*spaces;

	if (are_flags_valid(flags) == -1)
		return (-1);
	number = va_arg(args, unsigned int);
	to_add = generate_to_add(flags, number);
	if (to_add == 0)
		return (-1);
	spaces = gen_array(' ', flags->precision_x - ft_strlen(to_add));
	if (spaces == 0)
	{
		free(to_add);
		return (-1);
	}
	if (flags->minus == 1)
		return (minus_behavior(string, to_add, spaces));
	return (normal_behavior(string, to_add, spaces));
}
