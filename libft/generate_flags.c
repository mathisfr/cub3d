/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:41:35 by lloison           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:13 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_zeros(char *output, t_flags *flags, long long arg)
{
	char	*tmp;
	int		temp;

	if (output == 0)
		return (0);
	if (flags->precision_y > ft_strlen(output))
	{
		temp = 0;
		if (flags->blank == 1 && flags->precision == 0 && arg != 0)
			temp = 1;
		if (arg == 0 && flags->precision == 0 && flags->blank == 1)
			temp++;
		if (arg != 0 && flags->hashtag == 1 && flags->precision == 0)
			temp += 2;
		tmp = gen_array('0', flags->precision_y - ft_strlen(output) - temp);
		if (tmp == 0)
		{
			free(output);
			return (0);
		}
		output = ft_strjoinfree(tmp, output);
	}
	return (output);
}

char	*add_blank(char *output, t_flags *flags)
{
	char	*tmp;

	if (output == 0)
		return (0);
	if (flags->blank == 1)
	{
		tmp = ft_strdup(" ");
		if (tmp == 0)
		{
			free(output);
			return (0);
		}
		output = ft_strjoinfree(tmp, output);
	}
	return (output);
}

char	*add_minus(char *output, t_flags *flags, int is_n)
{
	char	*tmp;

	if (output == 0)
		return (0);
	if (is_n)
	{
		if ((output[0] == '0' || output[0] == ' ')
			&& (flags->precision == 0 || flags->blank == 1))
			output [0] = '-';
		else
		{
			tmp = ft_strdup("-");
			if (tmp == 0)
			{
				free(output);
				return (0);
			}
			return (ft_strjoinfree(tmp, output));
		}
	}
	return (output);
}

char	*add_plus(char *output, t_flags *flags, long long arg, int is_n)
{
	char	*tmp;

	if (output == 0)
		return (0);
	tmp = 0;
	if (flags->plus == 1 && is_n == 0)
	{
		if ((output[0] == ' ' || output[0] == '0')
			&& (flags->precision == 0 && flags->precision_y > 0)
			&& !(arg == 0 && ft_strlen(output) == 1))
		{
			output[0] = '+';
			return (output);
		}
		tmp = ft_strdup("+");
		if (tmp == 0)
		{
			free(output);
			return (0);
		}
		return (ft_strjoinfree(tmp, output));
	}
	if (tmp)
		free(tmp);
	return (output);
}

char	*format_hash_flag(char *output, int is_upper)
{
	char	*tmp;

	if (output == 0)
		return (0);
	if (is_upper == 1)
		tmp = ft_strdup("0X");
	else
		tmp = ft_strdup("0x");
	if (tmp == 0)
	{
		free(output);
		return (0);
	}
	return (ft_strjoinfree(tmp, output));
}
