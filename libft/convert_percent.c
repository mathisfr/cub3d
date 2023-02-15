/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:59:17 by lloison           #+#    #+#             */
/*   Updated: 2022/11/08 15:31:08 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_doublepercent(t_flags *flags, va_list args, t_sstring **string)
{
	char	*to_add;
	char	*spaces;

	(void) args;
	to_add = ft_strdup("%");
	if (to_add == 0)
		return (-1);
	spaces = gen_array(' ', flags->precision_x - 1);
	if (spaces == 0)
	{
		free(to_add);
		return (-1);
	}
	if (flags->minus == 1)
		return (minus_behavior(string, to_add, spaces));
	return (normal_behavior(string, to_add, spaces));
}
