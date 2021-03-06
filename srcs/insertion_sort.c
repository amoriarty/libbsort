/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 12:17:27 by alegent           #+#    #+#             */
/*   Updated: 2017/05/18 16:19:02 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsort.h"

void				insertion_sort(void **array, t_range range, t_bool (*sorted)(void *, void *))
{
	size_t			x;
	size_t			y;
	size_t			size;
	void			*swap;

	x = 0;
	size = range.end - range.start;
	if (size <= 1)
		return ;
	while (++x < size)
	{
		y = x - 1;
		swap = array[x];
		while ((int)y >= 0 && sorted(array[y], swap) == false)
		{
			array[y + 1] = array[y];
			y -= 1;
		}
		array[y + 1] = swap;
	}
}
