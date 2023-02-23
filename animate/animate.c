/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:17:09 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/23 17:06:31 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_animation(t_data *data, double time)
{
	static	int		i;
	static double	last_update;
	int				nbr_image;

	nbr_image = 10;
	if (time > last_update + 0.1 && (data->anim_state == TRUE || data->key_action == TRUE))
	{
		if (i == 0)
			data->anim_state = TRUE;
		if (i == 10)
		{
			i = 0;
			data->anim.img[nbr_image - 1]->enabled = FALSE;
			data->anim.img[i]->enabled = TRUE;
			data->anim_state = FALSE;
			return ;
		}
		last_update = time;
		if (i > 0)
			data->anim.img[i - 1]->enabled = FALSE;
		data->anim.img[i]->enabled = TRUE;
		i++;
	}
}
