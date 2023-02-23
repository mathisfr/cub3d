/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:17:09 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/23 15:35:00 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_animation(t_data *data, double time)
{
	static int		i;
	static double	last_update;

	if (time > last_update + 5)
	{
		last_update = time;
		if (data->anim.img[i - 1])
			data->anim.img[i - 1]->enabled = FALSE;
		data->anim.img[i]->enabled = TRUE;
		data->anim.delta_time[i] = data->delta_time;
		i = (i + 1) % 10;
	}
}
