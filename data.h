/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:12:02 by lloison           #+#    #+#             */
/*   Updated: 2023/02/13 13:18:37 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "player.h"
# include "map.h"

typedef struct s_data
{
	t_player	player;
	t_map		map;
}	t_data;

#endif