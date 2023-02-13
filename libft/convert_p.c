/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:47:05 by lloison           #+#    #+#             */
/*   Updated: 2022/11/07 10:52:29 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	are_flags_valid(t_flags *flags)
{
	if (flags->hashtag == 1 || flags->plus == 1)
		return (-1);
	return (0);
}

static int	get_length(unsigned long adr)
{
	int	count;

	count = 3;
	while (adr / 16 != 0)
	{
		count++;
		adr /= 16;
	}
	return (count);
}

static char	*get_address(unsigned long adr)
{
	int		length;
	char	*output;

	length = get_length(adr);
	output = (char *) malloc(sizeof(char) * (length + 1));
	if (output == 0)
		return (0);
	output[length] = 0;
	output[0] = '0';
	output[1] = 'x';
	while (adr / 16 > 0)
	{
		output[length - 1] = "0123456789abcdef"[adr % 16];
		length--;
		adr /= 16;
	}
	output[length - 1] = "0123456789abcdef"[adr % 16];
	return (output);
}

static char	*generate_to_add(t_flags *flags, unsigned long adr)
{
	char	*tmp;

	if (flags->precision == 0)
	{
		if (adr == 0)
			return (ft_strdup("0x0"));
		return (get_address(adr));
	}
	else
	{
		if (adr == 0)
			tmp = ft_strdup("0x0");
		else
			tmp = get_address(adr);
		if (tmp == 0)
			return (0);
		if (flags->precision_y < ft_strlen(tmp))
		{
			free(tmp);
			tmp = ft_substr(tmp, 0, flags->precision_y);
			return (tmp);
		}
		return (tmp);
	}
}

int	convert_p(t_flags *flags, va_list args, t_sstring **string)
{
	void	*ptr;
	char	*to_add;
	char	*spaces;

	if (are_flags_valid(flags) == -1)
		return (-1);
	ptr = va_arg(args, void *);
	to_add = generate_to_add(flags, *((unsigned long *)&ptr));
	if (to_add == 0)
		return (-1);
	spaces = gen_array(' ', flags->precision_x - ft_strlen(to_add));
	if (spaces == 0)
	{
		free (to_add);
		return (-1);
	}
	if (flags->minus == 1)
		return (minus_behavior(string, to_add, spaces));
	return (normal_behavior(string, to_add, spaces));
}
