/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:53:41 by lloison           #+#    #+#             */
/*   Updated: 2023/02/13 16:14:39 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing_error(char *message)
{
	ft_printf_error("PARSING ERROR: %s\n", message);
	exit (11);
}

void	system_error(char *prompt)
{
	perror(prompt);
	exit(1);
}

void	malloc_error(void)
{
	write(2, "ERROR: Malloc error\n", 20);
	exit(1);
}
