/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 10:57:41 by alegent           #+#    #+#             */
/*   Updated: 2017/05/29 13:35:01 by alegent          ###   ########.fr       */
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
	if (!array || !size)
		return ;
	power = floor_power_of_two(size);
	scale = size / power;
	if (!sorted)
		return ;
	while (_merge < power)
	{
		start = _merge * scale;
		end = start + 16 * scale;
		end = (end > size) ? size : end;
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
			if (sorted(array[start], array[end - 1]) == false)
				rotate(array, mid - start, range(start, end));
			else if (sorted(array[mid - 1], array[mid]) == false)
				merge(array, size, sorted);
			_merge += length * 2;
		}
		length += length;
	}
}
