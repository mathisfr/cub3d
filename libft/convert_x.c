/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:50:45 by lloison           #+#    #+#             */
/*   Updated: 2022/11/08 15:32:53 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	are_flags_valid(t_flags *flags)
{
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

static int	get_length(unsigned int number)
{
	int	count;

	count = 1;
	while (number / 16 != 0)
	{
		count++;
		number /= 16;
	}
	return (count);
}

static char	*get_hexa(unsigned int number, char *charset)
{
	int		length;
	char	*output;

	length = get_length(number);
	output = (char *) malloc(sizeof(char) * (length + 1));
	if (output == 0)
		return (0);
	output[length] = 0;
	while (number / 16 > 0)
	{
		output[length - 1] = charset[number % 16];
		length--;
		number /= 16;
	}
	output[length - 1] = charset[number % 16];
	return (output);
}

static char	*generate_to_add(t_flags *flags, unsigned int arg, int is_upper)
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
	if (is_upper == 1)
		output = get_hexa(arg, "0123456789ABCDEF");
	else
		output = get_hexa(arg, "0123456789abcdef");
	output = add_zeros(output, flags, arg);
	output = add_blank(output, flags);
	if (arg != 0 && flags->hashtag == 1)
		output = format_hash_flag(output, is_upper);
	if (output == 0)
		return (0);
	return (output);
}

int	convert_x(int is_upper, t_flags *flags, va_list args, t_sstring **string)
{
	unsigned int	number;
	char			*to_add;
	char			*spaces;

	if (are_flags_valid(flags) == -1)
		return (-1);
	number = va_arg(args, unsigned int);
	to_add = generate_to_add(flags, number, is_upper);
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
