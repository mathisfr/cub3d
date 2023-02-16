/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matfranc <matfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:41:15 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/16 12:42:18 by matfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawline3d(t_data *data, int *x, int *side, float *perpWallDist)
{

	int lineheight;
	int start;
	int end;

	// Je divise la distance par la hauteur de notre fenetre
	lineheight = (int)(data->_3d->height / *perpWallDist);

	// On commence à dessiner à la moitier de la fenetre et
	// à la moitier de la hauteur du mur pour centrer
	start = (data->_3d->height / 2) - (lineheight / 2);
	// Si on est en dehors de l'ecran je met start à zero
	// pour pas qu'il dessiner pour rien dehors
	if (start < 0)
		start = 0;

	// Pratiquement comme start
	end = (data->_3d->height / 2) + (lineheight / 2);
	if (end >= data->_3d->height)
		end = data->_3d->height - 1;

	// Change de couleur si le murs est vertical ou horizontal
	// X est l'axe horizontal de là où on dessine
	if (*side == 0)
		ft_line(data->_3d, *x, start, *x, end, 0xFFFFFF00);
	else
		ft_line(data->_3d, *x, start, *x, end, 0xFF00FFFF);
}
