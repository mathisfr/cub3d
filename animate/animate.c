/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:17:09 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/23 14:58:26 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_animation(t_data *data)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (data->anim.img[i - 1])
			data->anim.img[i - 1]->enabled = FALSE;
		data->anim.img[i]->enabled = TRUE;
		i++;
	}
	data->anim.img[i - 1]->enabled = FALSE;
	data->anim.img[0]->enabled = TRUE;
}
