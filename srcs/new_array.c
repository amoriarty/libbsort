/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:59:06 by alegent           #+#    #+#             */
/*   Updated: 2017/05/18 15:59:34 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsort.h"

void			**new_array(size_t size)
{
	size_t		i;
	void		**self;

	i = -1;
	if (!(self = (void **)malloc(sizeof(void *) * size)))
		return (NULL);
	while (++i < size)
		self[i] = NULL;
	return (self);
}
