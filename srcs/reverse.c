/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:01:17 by alegent           #+#    #+#             */
/*   Updated: 2017/05/19 15:54:09 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsort.h"

void				reverse(void **array, t_range range)
{
	size_t			i;
	size_t			stop;
	size_t			size;
	void			*swap;

	i = range.start; // !!! DOESN'T WORK WHEN OTHER THAT 0
	size = range.end - range.start;
	if (size < 2)
		return ;
	stop = ((range.end - 2) / 2);
	stop += range.start;
	stop += 1;
	while (i < stop)
	{
		swap = array[i];
		array[i] = array[range.end - i];
		array[range.end - i] = swap;
		i += 1;
	}
}
