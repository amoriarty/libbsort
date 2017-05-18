/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 12:17:27 by alegent           #+#    #+#             */
/*   Updated: 2017/05/18 15:32:58 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsort.h"

static void			**new_array(size_t size)
{
	size_t			i;
	void			**self;

	i = -1;
	if (!(self = (void **)malloc(sizeof(void *) * size)))
		return (NULL);
	while (++i < size)
		self[i] = NULL;
	return (self);
}

static void			sort(void **array, void **sarray, t_range range, t_bool (*sorted)(void *, void *))
{
	size_t			i;
	size_t			x;
	size_t			y;

	i = range.start - 1;
	while (++i < range.end)
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
	}
}

void				insertion_sort(void **array, t_range range, t_bool (*sorted)(void *, void *))
{
	size_t			i;
	size_t			x;
	void			**sarray;

	if (!(sarray = new_array(range.end - range.start)))
		return ;
	sort(array, sarray, range, sorted);
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
