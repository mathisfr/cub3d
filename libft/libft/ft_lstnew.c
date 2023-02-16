/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:39:46 by lloison           #+#    #+#             */
/*   Updated: 2022/11/01 18:44:00 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*e;

	e = (t_list *) malloc(sizeof(t_list));
	if (e == 0)
		return (0);
	e->content = content;
	e->next = 0;
	return (e);
}
