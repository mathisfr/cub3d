/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_return.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:55:30 by lloison           #+#    #+#             */
/*   Updated: 2022/11/18 14:05:11 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

void	*free_return(unsigned int arg_count, ...)
{
	va_list			args;
	unsigned int	i;
	void			*tmp;

	if (arg_count > 0)
	{
		va_start(args, arg_count);
		i = 0;
		while (i < arg_count)
		{
			tmp = va_arg(args, void *);
			free(tmp);
			i++;
		}
		va_end(args);
	}
	return (0);
}
