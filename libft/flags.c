/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:58:29 by lloison           #+#    #+#             */
/*   Updated: 2022/11/06 17:37:52 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*init_flags(void)
{
	t_flags	*output;

	output = (t_flags *)malloc(sizeof(t_flags));
	if (output == 0)
		return (0);
	output->minus = 0;
	output->plus = 0;
	output->hashtag = 0;
	output->precision = 0;
	output->blank = 0;
	output->zero = 0;
	output->precision_x = 0;
	output->precision_y = 0;
	output->flags_length = 0;
	return (output);
}

static void	parsing_step1(t_flags **output, const char *s, size_t *i)
{
	while (s[*i] == '-' || s[*i] == '+'
		|| s[*i] == '#' || s[*i] == ' ' || s[*i] == '0')
	{
		if ((*output)->minus == 0 && s[*i] == '-')
			(*output)->minus = 1;
		else if ((*output)->plus == 0 && s[*i] == '+')
			(*output)->plus = 1;
		else if ((*output)->hashtag == 0 && s[*i] == '#')
			(*output)->hashtag = 1;
		else if ((*output)->blank == 0 && s[*i] == ' ')
			(*output)->blank = 1;
		else if ((*output)->zero == 0 && s[*i] == '0')
			(*output)->zero = 1;
		*i += 1;
	}
}

static void	parsing_step2_4(int is_2, t_flags **output,
	const char *s, size_t *i)
{
	if (ft_isdigit(s[*i]))
	{	
		if (is_2 == 1)
			(*output)->precision_x = ft_atoi(s + *i);
		else
			(*output)->precision_y = ft_atoi(s + *i);
	}
	while (ft_isdigit(s[*i]))
		*i += 1;
}

t_flags	*get_flags(const char *s)
{
	t_flags	*output;
	size_t	i;

	output = init_flags();
	if (output == 0)
		return (0);
	i = 0;
	parsing_step1(&output, s, &i);
	parsing_step2_4(1, &output, s, &i);
	if (s[i] == '.')
	{
		output->precision = 1;
		i++;
	}
	parsing_step2_4(0, &output, s, &i);
	output->flags_length = i;
	if (s[i] == 'c' || s[i] == 's' || s[i] == 'p' || s[i] == 'd' || s[i] == 'i'
		|| s[i] == 'u' || s[i] == 'x' || s[i] == 'X' || s[i] == '%')
		return (output);
	return (0);
}
