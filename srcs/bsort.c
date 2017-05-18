/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 10:57:41 by alegent           #+#    #+#             */
/*   Updated: 2017/05/18 12:08:06 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsort.h"


// DEBUG
#include <stdio.h>

t_bool				bsort(void **array, size_t size, t_bool (*f)(void *, void *))
{
	size_t			power;
	size_t			scale;
	size_t			merge;
	size_t			length;
	size_t			start;
	size_t			mid;
	size_t			end;

	(void)f;
	merge = 0;
	length = 16;
	power = floor_power_of_two(size);
	scale = size / power;
	while (merge < power)
	{
		start = merge * scale;
		end = start + 16 * scale;
		// insertion_sort(array, range(start, end));
		merge += 16;
	}
	while (length < power)
	{
		merge = 0;
		while (merge < power)
		{
			start = merge * scale;
			mid = (merge + length) * scale;
			end = (merge + length * 2) * scale;
			// if (array[end - 1] < array[start]) // FUNCTION CONDITION;
				// rotate(array, mid - start, range(start, end));
			// else if (array[mid - 1] > array[mid]) // FUNCTION CONDITION;
				// merge(array, range(start, mid), range(mid, end));
			merge += length * 2;
		}
		length += length;
	}

	// DEBUG LOOP
	size_t			i;
	i = -1;
	while (++i < size)
		ft_putendl(array[i]);
	// END DEBUG LOOP

	return (false);
}