/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 10:57:41 by alegent           #+#    #+#             */
/*   Updated: 2017/05/18 12:25:18 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsort.h"


// DEBUG
#include <stdio.h>

void				bsort(void **array, size_t size, t_bool (*f)(void *, void *))
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
	while (_merge < power)
	{
		start = _merge * scale;
		end = start + 16 * scale;
		insertion_sort(array, range(start, end), f);
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
			if (array[end - 1] < array[start]) // FUNCTION CONDITION;
				rotate(array, mid - start, range(start, end));
			else if (array[mid - 1] > array[mid]) // FUNCTION CONDITION;
				merge(array, range(start, mid), range(mid, end));
			_merge += length * 2;
		}
		length += length;
	}

	// DEBUG LOOP
	size_t			i;
	i = -1;
	while (++i < size)
		ft_putendl(array[i]);
	// END DEBUG LOOP
}