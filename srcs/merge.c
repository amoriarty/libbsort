/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 12:15:37 by alegent           #+#    #+#             */
/*   Updated: 2017/05/22 17:44:31 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsort.h"

void				mrg(void **array, size_t n, size_t m, t_bool (*sorted)(void *, void *))
{
	size_t			i;
	size_t			j;
	size_t			k;
	void			**final;

	i = 0;
	j = m;
	k = 0;
	if (!(final = (void **)malloc(sizeof(void *) * n)))
		return ;
	while (k < n)
	{
		if (j == n)
			final[k] = array[i++];
		else if (i == m)
			final[k] = array[j++];
		else if (sorted(array[j], array[i]) == true)
			final[k] = array[j++];
		else
			final[k] = array[i++];
		k += 1;
	}
	i = 0;
	while (i < n)
	{
		array[i] = final[i];
		i += 1;
	}
	free(final);
}

void				merge(void **array, size_t n, t_bool (*sorted)(void *, void *))
{
	size_t			middle;

	if (n < 2)
		return ;
	middle = n / 2;
	merge(array, middle, sorted);
	merge(array + middle, n - middle, sorted);
	mrg(array, n, middle, sorted);
}
