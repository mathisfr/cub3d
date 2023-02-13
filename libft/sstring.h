/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sstring.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:27:00 by lloison           #+#    #+#             */
/*   Updated: 2022/11/06 14:32:12 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSTRING_H
# define SSTRING_H

typedef struct s_sstring
{
	char	*text;
	size_t	length;
}	t_sstring;

t_sstring	*init_sstring(void);
void		*free_sstring(t_sstring **string);
int			add_to_text(t_sstring **string, char *to_add, size_t size);

#endif
