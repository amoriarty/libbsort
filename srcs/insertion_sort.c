/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 12:17:27 by alegent           #+#    #+#             */
/*   Updated: 2017/05/18 15:59:46 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsort.h"

static void			sort(void **array, void **sarray, t_range range, t_bool (*sorted)(void *, void *))
{
	size_t			i;
	size_t			x;

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
			slide_data(sarray, x, range.end - range.start);
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
