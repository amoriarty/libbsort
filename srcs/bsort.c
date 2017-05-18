/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 10:57:41 by alegent           #+#    #+#             */
/*   Updated: 2017/05/18 15:55:01 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsort.h"

void				bsort(void **array, size_t size, t_bool (*sorted)(void *, void *))
{
	size_t			power;
	size_t			scale;
	size_t			_merge;
	size_t			length;
	size_t			start;
	size_t			mid;
	size_t			end;

	_merge = 0;
	length = 16;
	power = floor_power_of_two(size);
	scale = size / power;
	if (!sorted)
		return ;
	if (size < 16)
	{
		insertion_sort(array, range(0, size), sorted);
		return ;
	}
	while (_merge < power)
	{
		start = _merge * scale;
		end = start + 16 * scale;
		insertion_sort(array, range(start, end), sorted);
		_merge += 16;
	}
	while (length < power)
	{
		_merge = 0;
		while (_merge < power)
		{
			start = _merge * scale;
			mid = (_merge + length) * scale;
			end = (_merge + length * 2) * scale;
			// !!! end - 1 may be wrong and will have to be remplace by just end
			if (sorted(array[start], array[end - 1]) == false) // if (array[end - 1] < array[start])
				rotate(array, mid - start, range(start, end));
			else if (sorted(array[mid - 1], array[mid]) == false) // else if (array[mid - 1] > array[mid])
				merge(array, range(start, mid), range(mid, end));
			_merge += length * 2;
		}
		length += length;
	}
}
