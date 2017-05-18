/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 12:17:27 by alegent           #+#    #+#             */
/*   Updated: 2017/05/18 15:22:38 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsort.h"

void				insertion_sort(void **array, t_range range, t_bool (*sorted)(void *, void *))
{
	size_t			i;
	size_t			x;
	size_t			y;
	void			**sarray;

	x = -1;
	i = range.start;
	if (!(sarray = (void **)malloc(sizeof(void *) * range.end - range.start)))
		return ;
	while (++x < range.end - range.start)
		sarray[x] = NULL;
	while (i < range.end)
	{
		x = 0;
		while (sarray[x] && sorted(array[i], sarray[x]) == false)
			x += 1;
		if (!sarray[x])
			sarray[x] = array[i];
		else
		{
			y = 0;
			while (y < range.end - range.start && sarray[y])
				y += 1;
			while (y > x)
			{
				sarray[y] = sarray[y - 1];
				y -= 1;
			}
			sarray[x] = array[i];
		}
		i += 1;
	}
	x = 0;
	i = range.start;
	while (i < range.end)
	{
		array[i] = sarray[x];
		i += 1;
		x += 1;
	}
	free(sarray);
}
