/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:54:39 by lloison           #+#    #+#             */
/*   Updated: 2023/02/13 16:14:28 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft_e.h"
# include "data.h"
# include "defines.h"
# include "map.h"
# include "player.h"
# include "vector.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/* - - - - - error.c - - - - - */
void			parsing_error(char *message);
void			system_error(char *prompt);
void			malloc_error(void);

#endif