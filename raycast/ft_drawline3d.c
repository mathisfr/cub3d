/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:41:15 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/16 15:41:04 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawline3d(t_data *data, int *x, int *side, float *perpWallDist)
{

	int lineheight;
	int start;
	int end;

	// Je divise la distance par la hauteur de notre fenetre
	if (*perpWallDist < 0.5)
		lineheight = data->_3d->height;
	else
		lineheight = (int)((float)data->_3d->height / *perpWallDist);

	// On commence à dessiner à la moitier de la fenetre et
	// à la moitier de la hauteur du mur pour centrer
	start = (data->_3d->height / 2.0) - (lineheight / 2.0);
	// Si on est en dehors de l'ecran je met start à zero
	// pour pas qu'il dessiner pour rien dehors
	if (start < 0)
		start = 0;

	// Pratiquement comme start
	end = (data->_3d->height / 2.0) + (lineheight / 2.0);
	if (end >= (int)data->_3d->height)
		end = data->_3d->height - 1;

	// Change de couleur si le murs est vertical ou horizontal
	// X est l'axe horizontal de là où on dessine
	if (*side == 0)
		ft_line(data->_3d, *x, start, *x, end, 0xFFFFFF00);
	else
		ft_line(data->_3d, *x, start, *x, end, 0xFF00FFFF);
}
