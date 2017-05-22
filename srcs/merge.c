/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 12:15:37 by alegent           #+#    #+#             */
/*   Updated: 2017/05/22 16:34:22 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsort.h"

static void			copy_array(void **origin, void **dst, size_t size)
{
	size_t			i;

	i = -1;
	while (++i < size)
		dst[i] = origin[i];
}

static void			top_down_merge(void **array, void **work, t_range r, t_bool (*sorted)(void *, void *))
{
	size_t			i;
	size_t			j;
	size_t			k;
	size_t			middle;

	i = r.start;
	j = ((r.end - r.start) / 2) + r.start;
	k = 0;
	middle = j;
	while (k < r.end - r.start)
	{
		if (i < middle && (j >= r.end || sorted(array[i], array[j]) == true))
		{
			work[k] = array[i];
			i += 1;
		}
		else
		{
			work[k] = array[j];
			j += 1;
		}
		k += 1;
	}
}

static void			top_down(void **array, void **work, t_range r, t_bool (*sorted)(void *, void *))
{
	size_t			middle;

	if (r.end - r.start < 2)
		return ;
	middle = ((r.end - r.start) / 2) + r.start;
	top_down(array, work, range(r.start, middle), sorted);
	top_down(array, work, range(middle, r.end), sorted);
	top_down_merge(array, work, r, sorted);
}

// ERROR STILL OCCURES IN MERGE SORT.
void				merge(void **array, t_range a, t_range b, t_bool (*sorted)(void *, void *))
{
	void			**_a;
	void			**_b;

	if (!(_a = (void **)malloc(sizeof(void *) * (a.end - a.start))))
		return ;
	if (!(_b = (void **)malloc(sizeof(void *) * (b.end - b.start))))
		return ;
	top_down(array, _a, a, sorted);
	top_down(array, _b, b, sorted);
	copy_array(_a, array + a.start, a.end - b.start);
	copy_array(_b, array + b.start, b.end - b.start);
	free(_a);
	free(_b);
}
